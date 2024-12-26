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

   std::string name;

   Vector3 ambientColor;
   Texture diffuseComponent;
   Vector3 specularColor;
   float shininess;
};

#endif // MATERIAL_H
