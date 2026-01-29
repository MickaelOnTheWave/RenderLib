#include "Scene.h"

#include "utils/ImageLoader.h"

unsigned int Scene::AddTexture(const std::string& filename, const std::string& _name)
{
   const ImageData textureData = ImageLoader::FromFile(filename);
   auto newTexture = new Texture(textureData, filename, Texture::SourceType::File, _name);
   return textureManager.Add(newTexture);
}

unsigned int Scene::AddTexture(const Vector3& color, const std::string& _name)
{
   const ImageData textureData = ImageLoader::FromColor(color);
   auto newTexture = new Texture(textureData, "color", Texture::SourceType::PlainColor, _name);
   return textureManager.Add(newTexture);
}

unsigned int Scene::AddMaterial(Material& material)
{
   return materialManager.Add(material);
}

unsigned int Scene::AddGeometry(Geometry* geometry)
{
   return geometryManager.Add(geometry);
}

unsigned int Scene::AddSinglePartModel(const unsigned int geometryId, const unsigned int materialId,
                                       const std::string& _name)
{
   Model newModel(_name);

   Model::ModelPart part;
   part.geometryId = geometryId;
   part.materialId = materialId;
   newModel.parts.push_back(part);
   return modelManager.Add(newModel);
}

unsigned int Scene::AddInstance(ModelInstance* instance)
{
   return instanceManager.Add(instance);
}

unsigned int Scene::AddCamera(Camera* camera)
{
   return cameraManager.Add(camera);
}

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
