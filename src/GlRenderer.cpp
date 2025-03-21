#include "GlRenderer.h"

#include "ShaderPrograms/ShaderPrograms.h"

#include <iostream>

namespace Debug
{
   void PrintVec(const std::string& label, const Vector3& data)
   {
      std::cout << label << " : (" << data.X() << "," << data.Y() << "," << data.Z() << ")" << std::endl;
   }

   void PrintCameraVecs(AbstractGlCamera* camera)
   {
      Debug::PrintVec("Pos", camera->GetPosition());
      Debug::PrintVec("Dir", camera->GetDirection());
      Debug::PrintVec("Up", camera->GetUpVector());
      std::cout << std::endl;
   }

   void PrintCameraMatrix(AbstractGlCamera* camera)
   {
      const auto cameraTransform = camera->GetTransformMatrix();
      std::cout << "Camera Matrix :" << std::endl;
      for (int i=0; i<4; ++i)
      {
         for (int j=0; j<4; ++j)
            std::cout << cameraTransform[j + 4*i] << "\t";
         std::cout << std::endl;
      }
      std::cout << std::endl;
   }
}

GlRenderer::GlRenderer(AbstractGlCamera* _camera)
   : camera(_camera)
{
   shaderPrograms[ShaderEnum::SIMPLE_TEXTURING] = std::make_unique<SimpleTexturingProgram>();
   shaderPrograms[ShaderEnum::PHONG_LIGHTING]   = std::make_unique<PhongLightingProgram>();
   shaderPrograms[ShaderEnum::OBJECT_COLOR_ONLY]= std::make_unique<ObjectColorProgram>();
   shaderPrograms[ShaderEnum::TESTING]          = std::make_unique<TestingProgram>();
   shaderPrograms[ShaderEnum::PROCEDURAL_EYE]   = std::make_unique<ProceduralEyeProgram>();

   for (const auto& shader : shaderPrograms)
      renderObjectsPerShader[shader.second.get()] = RenderObjectsMap();

   // Default shader
   SetRenderShader(ShaderEnum::PHONG_LIGHTING);
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

unsigned int GlRenderer::AddTexture(const std::string &file, const int colorChannels)
{
   return textureManager.AddTexture(file, colorChannels);
}

unsigned int GlRenderer::AddTexture(const ImageData &imageData, const int glFormat)
{
   return textureManager.AddTexture(imageData, glFormat);
}

unsigned int GlRenderer::AddTexture(const Vector3 &color)
{
   return textureManager.AddPlainColorTexture(color);
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

   //glEnable(GL_CULL_FACE);
   //glCullFace(GL_BACK);

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

      //Debug::PrintCameraVecs(camera);
      //Debug::PrintCameraMatrix(camera);

      currentShader->SetUniformVec3("cameraPosition", camera->GetPosition());
      currentShader->SetUniformVec3("cameraDirection", camera->GetPosition());
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

