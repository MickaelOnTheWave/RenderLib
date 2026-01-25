#ifndef SCENE_H
#define SCENE_H

#include "managers/CameraManager.h"
#include "managers/MaterialManager.h"
#include "managers/TextureManager.h"
#include "resources/Geometry.h"
#include "resources/Light.h"
#include "resources/Model.h"
#include "resources/ModelInstance.h"

class Scene
{
public:
   Scene();

   const std::vector<Texture*>& GetTextures() const;
   const std::vector<Material>& GetMaterials() const;
   const std::vector<Geometry*>& GetGeometries() const;
   const std::vector<Model>& GetModels() const;
   const std::vector<ModelInstance*>& GetInstances() const;

   Camera* GetCurrentCamera();

private:
   TextureManager textureManager;
   MaterialManager materialManager;
   ValueResourceManager<Model> modelManager;
   ReferenceResourceManager<Geometry> geometryManager;
   ReferenceResourceManager<ModelInstance> instanceManager;

   CameraManager cameraManager;
   ReferenceResourceManager<Light> lightManager;
};

#endif // SCENE_H
