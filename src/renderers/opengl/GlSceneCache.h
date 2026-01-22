#ifndef GLSCENECACHE_H
#define GLSCENECACHE_H

#include <vector>
#include "renderers/opengl/GlMaterial.h"
#include "renderers/opengl/GlModel.h"
#include "renderers/opengl/GlTexture.h"
#include "scene/Scene.h"

class GlSceneCache
{
public:
   GlSceneCache();

   void Update(const Scene& scene);

   const std::vector<GlModel>& GetModels() const;

private:
   void CreateGpuRepresentation(const Scene& scene);
   void UpdateGpuRepresentation(const Scene& scene);

   void CreateTextureMapping(const Scene& scene);
   void CreateMaterialMapping(const Scene& scene);
   void CreateModelMapping(const Scene& scene);

   const GlTexture* FindGlTexture(const unsigned int sceneId) const;
   const GlMaterial* FindGlMaterial(const unsigned int sceneId) const;
   const GlGeometry* FindGlGeometry(const unsigned int sceneId) const;

   bool gpuRepresentationCreated = false;
   std::vector<GlTexture> glTextures;
   std::vector<GlMaterial> glMaterials;
   std::vector<GlGeometry> glGeometry;
   std::vector<GlModel> glModels;
};

#endif // GLSCENECACHE_H
