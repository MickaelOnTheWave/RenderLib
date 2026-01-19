#include "Scene.h"

Scene::Scene() {}

const std::vector<Texture*>& Scene::GetTextures() const
{
   return textureManager.GetData();
}
