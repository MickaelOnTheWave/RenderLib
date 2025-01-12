#include "GlRenderer.h"

#include "ShaderPrograms/ShaderPrograms.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GlRenderer::GlRenderer(AbstractGlCamera* _camera)
   : camera(_camera)
{
   shaderPrograms[ShaderEnum::SIMPLE_TEXTURING] = std::make_unique<SimpleTexturingProgram>();
   shaderPrograms[ShaderEnum::PHONG_LIGHTING]   = std::make_unique<PhongLightingProgram>();
   shaderPrograms[ShaderEnum::OBJECT_COLOR_ONLY]= std::make_unique<ObjectColorProgram>();
   shaderPrograms[ShaderEnum::TESTING]          = std::make_unique<TestingProgram>();

   for (const auto& shader : shaderPrograms)
      renderObjectsPerShader[shader.second.get()] = RenderObjectsMap();

   // Default shader
   SetRenderShader(ShaderEnum::TESTING);
}

GlRenderer::~GlRenderer()
{
   ClearScene();
   ClearMaterials();
}

void GlRenderer::SetCamera(AbstractGlCamera* newCamera)
{
   camera = newCamera;
}

void GlRenderer::ClearScene()
{
   for (auto& renderObjs : renderObjectsStorage)
   {
      for (auto* renderInstance : renderObjs.second)
      {
         delete renderInstance;
      }
      renderObjs.second.clear();
      delete renderObjs.first;
   }
   renderObjectsPerShader.clear();
}

void GlRenderer::ClearMaterials()
{
   for (auto material : materials)
      delete material;
   materials.clear();
}

void GlRenderer::SetRenderShader(const ShaderEnum &renderMode)
{
   activeShaderProgram = shaderPrograms[renderMode].get();
}

void GlRenderer::SetClearColor(const float r, const float g, const float b)
{
   clearColorR = r;
   clearColorG = g;
   clearColorB = b;
}

unsigned int GlRenderer::AddTexture(const std::string &file, const int format)
{
   const int textureId = CreateGlTexture(Texture(file, format));
   textureObjects.push_back(textureId);
   return textureId;
}

void GlRenderer::AddMaterial(Material *material)
{
   materials.push_back(material);
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object)
{
   AddRenderObject(object, activeShaderProgram);
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object, const ShaderEnum &shader)
{
   ShaderProgram* renderObjectShader = shaderPrograms[shader].get();
   if (!renderObjectShader)
      renderObjectShader = activeShaderProgram;
   AddRenderObject(object, renderObjectShader);
}

void GlRenderer::PrepareRendering()
{
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glEnable(GL_DEPTH_TEST);

   activeShaderProgram->use();
}

void GlRenderer::Render()
{
   glClearColor(clearColorR, clearColorG, clearColorB, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   for (const auto& shaderRenderObj : renderObjectsPerShader)
   {
      if (shaderRenderObj.second.empty())
         continue;

      ShaderProgram* currentShader = shaderRenderObj.first;
      currentShader->use();

      const Vector3 camPos = camera->GetPosition();
      std::cout << "Camera Pos : (" << camPos.X() << "," << camPos.Y() << "," << camPos.Z() << ")" << std::endl;

      currentShader->SetUniformVec3("cameraPosition", camera->GetPosition());
      currentShader->SetUniformMat4("cameraProjection", camera->GetProjectionMatrix());
      currentShader->SetUniformMat4("cameraTransform", camera->GetTransformMatrix());

      if (lightPosition)
         currentShader->SetUniformVec3("lightPosition", lightPosition->GetData());

      if (lightColor)
         currentShader->SetUniformVec3("lightColor", lightColor->GetData());

      glPushMatrix();
         for (const auto& renderObj : shaderRenderObj.second)
         {
            renderObj.first->PrepareRendering(currentShader->GetId());

            currentShader->SetUniformMaterial(renderObj.first->GetMaterial());

            for (const auto renderedObj : renderObj.second)
            {
               currentShader->SetUniformMat4("objectTransform", renderedObj->GetTransform());
               currentShader->SetUniformVec3("objectColor", renderedObj->GetColor());

               renderObj.first->Render();
            }
         }

      glPopMatrix();
   }
}

void GlRenderer::SetTempLights(Vector3 *position, Vector3 *color)
{
   lightPosition = position;
   lightColor = color;
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object, ShaderProgram *shader)
{
   RenderObjectsMap& renderObjectMap = renderObjectsPerShader[shader];
   AddToObjectMap(object, renderObjectMap);
   AddToObjectMap(object, renderObjectsStorage);
}

void GlRenderer::AddToObjectMap(GlRenderedInstance *object, RenderObjectsMap &objectMap)
{
   auto renderObjIt = objectMap.find(object->GetRenderObject());
   if (renderObjIt != objectMap.end())
      renderObjIt->second.push_back(object);
   else
      objectMap[object->GetRenderObject()] = {object};
}

unsigned int GlRenderer::CreateGlTexture(const Texture &texture)
{
   unsigned int textureIndex = 0;

   int width, height, nrChannels;
   unsigned char *textureData = stbi_load(texture.file.c_str(), &width, &height, &nrChannels, 0);
   if (textureData)
   {
      const unsigned int textureIdQuantity = 1;
      glGenTextures(textureIdQuantity, &textureIndex);

      textureObjects.push_back(textureIndex);

      glBindTexture(GL_TEXTURE_2D, textureIndex);

      // Textures
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, texture.format, GL_UNSIGNED_BYTE, textureData);
      glGenerateMipmap(GL_TEXTURE_2D);

      stbi_image_free(textureData);
   }

   return textureIndex;
}
