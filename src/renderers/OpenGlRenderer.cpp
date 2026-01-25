#include "OpenGlRenderer.h"

#include <glad/gl.h>

#include "opengl/GlslShaderProgram.h"

OpenGlRenderer::OpenGlRenderer()
: polygonMode(GL_FILL)
{
   // Only while full shader support is not back
   const std::string vertexShaderFile = std::string(DATA_PATH) + "/basic.vert";
   const std::string fragmentShaderFile = std::string(DATA_PATH) + "/singleTexture.frag";
   currentShader = std::make_unique<GlslShaderProgram>(vertexShaderFile, fragmentShaderFile);
}

bool OpenGlRenderer::Initialize()
{
   const bool shaderOk = currentShader->Initialize();
   if (!shaderOk)
   {
      const std::vector<std::string> shaderErrors = currentShader->GetErrors();
      initErrors.insert(shaderErrors.end(), shaderErrors.begin(), shaderErrors.end());
   }
   return shaderOk;
}

bool OpenGlRenderer::Render(const Scene& scene)
{
   sceneCache.Update(scene);

   PrepareRenderPass();

   const std::vector<std::unique_ptr<GlModel>>& glModels = sceneCache.GetModels();

   for (const auto& model : glModels)
   {
      const std::vector<GlModelPart>& glModelParts = model->modelParts;
      for (const auto modelPart : glModelParts)
      {
         modelPart.PrepareRendering(currentShader);

         const auto modelInstances = sceneCache.GetModelInstances(&modelPart);
         for (const auto* instance : modelInstances)
         {
            glPushMatrix();
            PrepareRendering(*instance, currentShader);
            modelPart.Render();
            glPopMatrix();
         }
      }

   }
   return true;
}

void OpenGlRenderer::EnableWireframeMode(const bool enable)
{
   polygonMode = enable ? GL_LINE : GL_FILL;
}

void OpenGlRenderer::PrepareRenderPass()
{
   glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
   glEnable(GL_DEPTH_TEST);

   //glEnable(GL_CULL_FACE);
   //glCullFace(GL_BACK);
}

void OpenGlRenderer::PrepareRendering(const ModelInstance& instance, std::unique_ptr<GlslShaderProgram>& currentShader)
{
   currentShader->SetUniformMat4("objectTransform", instance.GetTransform());
   currentShader->SetUniformVec3("objectColor", instance.GetColor());
}
