#include "GlRenderer.h"

#include <glad/gl.h>
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
}

GlRenderer::~GlRenderer()
{
   ClearScene();
   ClearMaterials();
}

std::vector<int> GlRenderer::Initialize(const std::vector<ShaderProgram*>& _shaderPrograms)
{
    std::vector<int> shaderIds;
    for (const auto& shader : _shaderPrograms)
    {
        const int currentI = shaderPrograms.size();
        std::shared_ptr<ShaderProgram> managedShader(shader);
        shaderPrograms[currentI] = managedShader;
        shaderIds.push_back(currentI);
        renderObjectsPerShader[managedShader.get()] = RenderObjectsMap();
    }

    // Default shader is the first one
    SetCurrentShader(0);
    return shaderIds;
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

void GlRenderer::SetCurrentShader(const unsigned int shaderId)
{
   activeShaderProgram = shaderPrograms[shaderId].get();
}

void GlRenderer::SetClearColor(const float r, const float g, const float b)
{
   clearColorR = r;
   clearColorG = g;
   clearColorB = b;
}

unsigned int GlRenderer::AddTexture(const std::string &file, const int colorChannels, const std::string& name)
{
   return textureManager.AddTexture(file, colorChannels, name);
}

unsigned int GlRenderer::AddTexture(const ImageData &imageData, const std::string& name, const int glFormat)
{
   return textureManager.AddTexture(imageData, name, glFormat);
}

unsigned int GlRenderer::AddTexture(const Vector3 &color, const std::string& name)
{
   return textureManager.AddPlainColorTexture(color, name);
}

std::vector<GlTexture> GlRenderer::GetTextures() const
{
    return textureManager.GetTextureObjects();
}

void GlRenderer::AddMaterial(Material *material)
{
   materials.push_back(material);
}

std::vector<Material*> GlRenderer::GetMaterials()
{
    return materials;
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object)
{
   AddRenderObject(object, activeShaderProgram);
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object, const unsigned int shaderId)
{
   ShaderProgram* renderObjectShader = shaderPrograms[shaderId].get();
   if (!renderObjectShader)
      renderObjectShader = activeShaderProgram;
   AddRenderObject(object, renderObjectShader);
}

std::vector<GlRenderObject*> GlRenderer::ComputeRenderObjectsList() const
{
    std::vector<GlRenderObject*> objects;
    for (const auto renderObj : renderObjectsStorage)
        objects.push_back(renderObj.first);
    return objects;
}

std::vector<GlRenderedInstance*> GlRenderer::ComputeInstancesList() const
{
    std::vector<GlRenderedInstance*> instances;
    for (const auto renderObj : renderObjectsStorage)
    {
        for (const auto instance : renderObj.second)
            instances.push_back(instance);
    }
    return instances;
}

void GlRenderer::PrepareRendering()
{
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glEnable(GL_DEPTH_TEST);

   //glEnable(GL_CULL_FACE);
   //glCullFace(GL_BACK);

   if (activeShaderProgram)
       activeShaderProgram->use();
   else
       initErrors.emplace_back("Can't prepare rendering : No active Shader Program.");

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

      if (camera)
      {
          currentShader->SetUniformVec3("cameraPosition", camera->GetPosition());
          currentShader->SetUniformVec3("cameraDirection", camera->GetDirection());
          currentShader->SetUniformMat4("cameraProjection", camera->GetProjectionMatrix());
          currentShader->SetUniformMat4("cameraTransform", camera->GetTransformMatrix());
      }
      else
          renderErrors.emplace_back("Can't render : no camera.");

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

bool GlRenderer::HasError() const
{
    return !initErrors.empty() || !renderErrors.empty();
}

std::string GlRenderer::GetError() const
{
    if (!initErrors.empty())
        return initErrors.back();
    else if (!renderErrors.empty())
        return renderErrors.back();
    return "";
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

