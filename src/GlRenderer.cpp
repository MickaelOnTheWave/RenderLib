#include "GlRenderer.h"

#include "ShaderPrograms/ShaderPrograms.h"

GlRenderer::GlRenderer(AbstractGlCamera& _camera)
   : camera(_camera)
{
   shaderPrograms[ShaderEnum::SIMPLE_TEXTURING] = std::make_unique<SimpleTexturingProgram>();
   shaderPrograms[ShaderEnum::SIMPLE_LIGHTING]  = std::make_unique<PhongLightingProgram>();
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
}

void GlRenderer::ClearScene()
{
   for (auto& renderObjPerShader : renderObjectsPerShader)
   {
      for (auto& renderObjs : renderObjPerShader.second)
      {
         for (auto* renderInstance : renderObjs.second)
         {
            delete renderInstance;
         }
         renderObjs.second.clear();
         delete renderObjs.first;
      }
      renderObjPerShader.second.clear();
   }

   renderObjectsPerShader.clear();
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

      currentShader->SetUniformMat4("cameraTransform", camera.getTransformMatrix());

      const std::vector<float> lightPosition = {0.5f, -0.5f, 0.f};
      currentShader->SetUniformVec3("lightPosition", lightPosition);

      const std::vector<float> lightColor = {1.f, 0.5f, 1.f};
      currentShader->SetUniformVec3("lightColor", lightColor);

      glPushMatrix();
         for (const auto& renderObj : shaderRenderObj.second)
         {
            renderObj.first->PrepareRendering(currentShader->GetId());

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

void GlRenderer::AddRenderObject(GlRenderedInstance *object, ShaderProgram *shader)
{
   RenderObjectsMap& renderObjectMap = renderObjectsPerShader[shader];

   auto renderObjIt = renderObjectMap.find(object->GetRenderObject());
   if (renderObjIt != renderObjectMap.end())
      renderObjIt->second.push_back(object);
   else
      renderObjectMap[object->GetRenderObject()] = {object};
}
