#include "OpenGlRenderer.h"

#include <glad/gl.h>

#include "ShaderPrograms/GlslShaderProgram.h"

OpenGlRenderer::OpenGlRenderer()
: polygonMode(GL_FILL)
{
}

bool OpenGlRenderer::Initialize()
{
   return true;
}

bool OpenGlRenderer::Render(const Scene& scene)
{
   sceneCache.Update(scene);

   GlslShaderProgram* currentShader = nullptr;

   PrepareRenderPass();

   const std::vector<GlModel>& glModels = sceneCache.GetModels();

   for (const auto model : glModels)
   {
      const std::vector<GlModelPart>& glModelParts = model.modelParts;
      for (const auto modelPart : glModelParts)
      {
         modelPart.PrepareRendering();
         currentShader->SetUniformMaterial(modelPart.glMaterial);

         const auto modelInstances = sceneCache.GetModelInstances(modelPart);
         for (const auto& instance : modelInstances)
         {
            glPushMatrix();
            currentShader->SetUniformMat4("objectTransform", instance.GetTransform());
            currentShader->SetUniformVec3("objectColor", instance.GetColor());
            modelPart.Render(currentShader);
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
