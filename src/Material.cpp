#include "Material.h"

Material::Material(const std::string &_name)
  : name(_name)
{
}

Material::Material(const Material &other)
  : name(other.name),
  diffuseTextureId(other.diffuseTextureId),
  specularTextureId(other.specularTextureId), shininess(other.shininess)
{
}
