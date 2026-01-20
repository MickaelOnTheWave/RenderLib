#include "OpenGlRenderer.h"

#include <glad/gl.h>

OpenGlRenderer::OpenGlRenderer()
: polygonMode(GL_FILL)
{
}

void OpenGlRenderer::Initialize()
{

}

void OpenGlRenderer::Render(const Scene& scene)
{
   sceneCache.Update(scene);

   PrepareRenderPass();

   const std::vector<GlModel>& glModels = sceneCache.GetModels();

   for (const auto model : glModels)
   {
      const std::vector<GlModel::GlModelPart>& glModelParts = model.modelParts;
      for (const auto modelPart : glModelParts)
      {

      }

   }
/*
   for (const auto currentShader : renderMap)
   {
      for (const auto currentModel : currentShader.models)
      {
         currentModel.PrepareRendering();
         for (const auto currentGeom : currentModel.geometries)
         {
            currentGeom.Render();
         }
      }
   }*/
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
