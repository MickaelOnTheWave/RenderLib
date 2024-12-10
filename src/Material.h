#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "math/Vector3.h"

class Material
{
public:
   Material(const std::string& _name);

   std::string name;

   Vector3 ambientColor;
   Vector3 diffuseColor;
   Vector3 specularColor;
   float shininess;
};

#endif // MATERIAL_H
