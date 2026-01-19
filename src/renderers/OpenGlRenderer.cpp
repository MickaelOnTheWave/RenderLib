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
   if (!gpuRepresentationCreated)
   {
      CreateGpuRepresentation(scene);
      gpuRepresentationCreated = true;
   }
   else
      UpdateGpuRepresentation(scene);

   PrepareRenderPass();
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

void OpenGlRenderer::CreateGpuRepresentation(const Scene& scene)
{
   glTextures.clear();
   const std::vector<Texture*>& sceneTextures = scene.GetTextures();
   for (const auto texture : sceneTextures)
   {
      glTextures.push_back(GlTexture(*texture));
   }

   glMaterials.clear();
   const std::vector<Material>& sceneMaterials = scene.GetMaterials();
   for (const auto material : sceneMaterials)
   {
      GlMaterial glMaterial;
      glMaterial.sceneId = material.GetId();
      glMaterial.glDiffuseTextureId = FindGlTextureId(material.diffuseTextureId);
      glMaterial.glSpecularTextureId = FindGlTextureId(material.specularTextureId);
      glMaterials.push_back(glMaterial);
   }
}

void OpenGlRenderer::UpdateGpuRepresentation(const Scene& scene)
{

}

unsigned int OpenGlRenderer::FindGlTextureId(const unsigned int sceneId) const
{
   auto finder = [sceneId](const GlTexture texture) {
      return (texture.sceneId == sceneId);
   };
   auto itFound = std::find_if(glTextures.begin(), glTextures.end(), finder);
   return (itFound != glTextures.end() ? itFound->glTextureId : 0);
}
