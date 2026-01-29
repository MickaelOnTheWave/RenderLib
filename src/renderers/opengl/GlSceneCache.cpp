#include "GlSceneCache.h"

#include <stdexcept>
#include "GlGeometryFactory.h"

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

const std::vector<std::unique_ptr<GlModel> >& GlSceneCache::GetModels() const
{
   return glModels;
}

const std::vector<const ModelInstance*>& GlSceneCache::GetModelInstances(const GlModelPart* modelPart) const
{
   try
   {
      return renderMap.at(modelPart);
   }
   catch(std::out_of_range& e)
   {
      int i=0; // TODO find out why
   }
   catch(std::exception& e)
   {
      int j=0;
   }


}

bool GlSceneCache::CreateGpuRepresentation(const Scene& scene)
{
   try
   {
      CreateTextureMapping(scene);
      CreateMaterialMapping(scene);
      CreateGeometryMapping(scene);
      CreateModelMapping(scene);
      CreateInstanceMapping(scene);

      return true;
   }
   catch(std::out_of_range& e)
   {
   }
   catch(std::exception& e)
   {
   }

   return false;
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

void GlSceneCache::CreateGeometryMapping(const Scene& scene)
{
   glGeometries.clear();
   const std::vector<Geometry*>& sceneGeometries = scene.GetGeometries();
   for (Geometry* geometry : sceneGeometries)
   {
      glGeometries.push_back(GlGeometryFactory::Create(geometry));
   }
}

void GlSceneCache::CreateModelMapping(const Scene& scene)
{
   glModels.clear();
   const std::vector<Model> sceneModels = scene.GetModels();
   for (const auto model : sceneModels)
   {
      auto glModel = std::make_unique<GlModel>();
      glModel->sceneId = model.GetId();

      for (const auto modelPart : model.parts)
      {
         GlModelPart glModelPart;
         glModelPart.glGeometry = FindGlGeometry(modelPart.geometryId);
         glModelPart.glMaterial = FindGlMaterial(modelPart.materialId);
         glModel->modelParts.push_back(glModelPart);
      }
      glModels.push_back(std::move(glModel));
   }
}

void GlSceneCache::CreateInstanceMapping(const Scene& scene)
{
   renderMap.clear();
   const std::vector<ModelInstance*> sceneInstances = scene.GetInstances();
   for (const auto instance : sceneInstances)
   {
      auto glModel = FindGlModel(instance->GetModelId());
      for (const auto& glModelPart : glModel->modelParts)
         renderMap[&glModelPart].push_back(instance);
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
   auto finder = [sceneId](const std::unique_ptr<GlGeometry>& geometry) {
      return (geometry->sceneId == sceneId);
   };
   auto itFound = std::find_if(glGeometries.begin(), glGeometries.end(), finder);
   return (itFound != glGeometries.end() ? itFound->get() : nullptr);
}

const GlModel* GlSceneCache::FindGlModel(const unsigned int sceneId) const
{
   auto finder = [sceneId](const std::unique_ptr<GlModel>& model) {
      return (model->sceneId == sceneId);
   };
   auto itFound = std::find_if(glModels.begin(), glModels.end(), finder);
   return (itFound != glModels.end() ? itFound->get() : nullptr);
}
