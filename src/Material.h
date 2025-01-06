#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "math/Vector3.h"

struct Texture
{
   Texture() = default;
   Texture(const std::string& _file, const int _format);

   std::string file;
   int format;
};

class Material
{
public:
   Material(const std::string& _name);
   Material(const Material& other);

   std::string name;

   Vector3 ambientColor;
   unsigned int diffuseTextureId;
   Vector3 specularColor;
   float shininess;
};

#endif // MATERIAL_H
