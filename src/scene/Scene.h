#ifndef SCENE_H
#define SCENE_H

#include "managers/MaterialManager.h"
#include "managers/TextureManager.h"
#include "resources/Camera.h"
#include "resources/Geometry.h"
#include "resources/Model.h"

class Scene
{
public:
   Scene();

   const std::vector<Texture*>& GetTextures() const;
   const std::vector<Material>& GetMaterials() const;
   const std::vector<Model>& GetModels() const;

private:
   TextureManager textureManager;
   MaterialManager materialManager;
   ValueResourceManager<Model> modelManager;
   ResourceManager<Geometry> geometryManager;

   ValueResourceManager<Camera> cameraManager;
};

#endif // SCENE_H
