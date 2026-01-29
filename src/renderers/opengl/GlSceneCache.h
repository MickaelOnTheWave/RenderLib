#ifndef GLSCENECACHE_H
#define GLSCENECACHE_H

#include <memory>
#include <unordered_map>
#include <vector>

#include "renderers/opengl/GlMaterial.h"
#include "renderers/opengl/GlModel.h"
#include "renderers/opengl/GlTexture.h"
#include "scene/resources/ModelInstance.h"
#include "scene/Scene.h"

class GlSceneCache
{
public:
   GlSceneCache();

   void Update(const Scene& scene);

   const std::vector<std::unique_ptr<GlModel>>& GetModels() const;
   const std::vector<const ModelInstance*>& GetModelInstances(const GlModelPart* modelPart) const;

private:
   bool CreateGpuRepresentation(const Scene& scene);
   void UpdateGpuRepresentation(const Scene& scene);

   void CreateTextureMapping(const Scene& scene);
   void CreateMaterialMapping(const Scene& scene);
   void CreateGeometryMapping(const Scene& scene);
   void CreateModelMapping(const Scene& scene);
   void CreateInstanceMapping(const Scene& scene);

   const GlTexture* FindGlTexture(const unsigned int sceneId) const;
   const GlMaterial* FindGlMaterial(const unsigned int sceneId) const;
   const GlGeometry* FindGlGeometry(const unsigned int sceneId) const;
   const GlModel* FindGlModel(const unsigned int sceneId) const;

   bool gpuRepresentationCreated = false;
   std::vector<GlTexture> glTextures;
   std::vector<GlMaterial> glMaterials;
   std::vector<std::unique_ptr<GlGeometry>> glGeometries;
   std::vector<std::unique_ptr<GlModel>> glModels;

   using RenderObjectsMap = std::unordered_map<const GlModelPart*, std::vector<const ModelInstance*>>;
   RenderObjectsMap renderMap;
};

#endif // GLSCENECACHE_H
