#include "Material.h"

Material::Material(const std::string &_name)
  : NamedEntity(_name)
{
}

Material::Material(const Material &other)
  : NamedEntity(other),
  diffuseTextureId(other.diffuseTextureId),
  specularTextureId(other.specularTextureId), shininess(other.shininess)
{
}
