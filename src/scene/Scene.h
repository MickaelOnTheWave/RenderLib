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

private:
   TextureManager textureManager;
   MaterialManager materialManager;
   ResourceManager<Model> modelManager;
   ResourceManager<Geometry> geometryManager;

   ResourceManager<Camera> cameraManager;
};

#endif // SCENE_H
