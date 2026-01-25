#include "Scene.h"

Scene::Scene() {}

const std::vector<Texture*>& Scene::GetTextures() const
{
   return textureManager.GetData();
}

const std::vector<Material>& Scene::GetMaterials() const
{
   return materialManager.GetData();
}

const std::vector<Geometry*>& Scene::GetGeometries() const
{
   return geometryManager.GetData();
}

const std::vector<Model>& Scene::GetModels() const
{
   return modelManager.GetData();
}

const std::vector<ModelInstance*>& Scene::GetInstances() const
{
   return instanceManager.GetData();
}
