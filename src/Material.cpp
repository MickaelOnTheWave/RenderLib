#include "Material.h"

Texture::Texture(const std::string &_file, const int _format)
  : file(_file), format(_format)
{
}

Material::Material(const std::string &_name)
  : name(_name)
{
}
