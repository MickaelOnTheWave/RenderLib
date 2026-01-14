#include "Material.h"

Material::Material(const std::string &_name)
  : EngineEntity(_name)
{
}

Material::Material(const Material &other)
  : EngineEntity(other),
  diffuseTextureId(other.diffuseTextureId),
  specularTextureId(other.specularTextureId), shininess(other.shininess)
{
}
