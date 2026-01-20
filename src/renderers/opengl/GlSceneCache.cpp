#include "GlSceneCache.h"

GlSceneCache::GlSceneCache() {}

void GlSceneCache::Update(const Scene& scene)
{
   if (!gpuRepresentationCreated)
   {
      CreateGpuRepresentation(scene);
      gpuRepresentationCreated = true;
   }
   else
      UpdateGpuRepresentation(scene);
}

const std::vector<GlModel>& GlSceneCache::GetModels() const
{
   return glModels;
}

void GlSceneCache::CreateGpuRepresentation(const Scene& scene)
{
   CreateTextureMapping(scene);
   CreateMaterialMapping(scene);
   CreateModelMapping(scene);
}

void GlSceneCache::UpdateGpuRepresentation(const Scene& scene)
{

}

void GlSceneCache::CreateTextureMapping(const Scene& scene)
{
   glTextures.clear();
   const std::vector<Texture*>& sceneTextures = scene.GetTextures();
   for (const auto texture : sceneTextures)
   {
      glTextures.push_back(GlTexture(*texture));
   }
}

void GlSceneCache::CreateMaterialMapping(const Scene& scene)
{
   glMaterials.clear();
   const std::vector<Material>& sceneMaterials = scene.GetMaterials();
   for (const auto material : sceneMaterials)
   {
      GlMaterial glMaterial;
      glMaterial.sceneId = material.GetId();
      glMaterial.glDiffuseTexture = FindGlTexture(material.diffuseTextureId);
      glMaterial.glSpecularTexture = FindGlTexture(material.specularTextureId);
      glMaterial.shininess = material.shininess;
      glMaterials.push_back(glMaterial);
   }
}

void GlSceneCache::CreateModelMapping(const Scene& scene)
{
   glModels.clear();
   const std::vector<Model> sceneModels = scene.GetModels();
   for (const auto model : sceneModels)
   {
      GlModel glModel;
      glModel.sceneId = model.GetId();

      for (const auto modelPart : model.parts)
      {
         GlModel::GlModelPart glModelPart;
         glModelPart.glGeometry = FindGlGeometry(modelPart.geometryId);
         glModelPart.glMaterial = FindGlMaterial(modelPart.materialId);
         glModel.modelParts.push_back(glModelPart);
      }
      glModels.push_back(glModel);
   }
}

const GlTexture* GlSceneCache::FindGlTexture(const unsigned int sceneId) const
{
   auto finder = [sceneId](const GlTexture& texture) {
      return (texture.sceneId == sceneId);
   };
   auto itFound = std::find_if(glTextures.begin(), glTextures.end(), finder);
   return (itFound != glTextures.end()) ? &(*itFound) : nullptr;
}

const GlMaterial* GlSceneCache::FindGlMaterial(const unsigned int sceneId) const
{
   auto finder = [sceneId](const GlMaterial& material) {
      return (material.sceneId == sceneId);
   };
   auto itFound = std::find_if(glMaterials.begin(), glMaterials.end(), finder);
   return (itFound != glMaterials.end() ? &(*itFound) : nullptr);
}

const GlGeometry* GlSceneCache::FindGlGeometry(const unsigned int sceneId) const
{
}
