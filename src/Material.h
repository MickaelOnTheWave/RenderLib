#ifndef MATERIAL_H
#define MATERIAL_H

#include "NamedEntity.h"

#include <string>

class Material : public NamedEntity
{
public:
   Material(const std::string& _name);
   Material(const Material& other);

   unsigned int diffuseTextureId;
   unsigned int specularTextureId;
   float shininess;
};

#endif // MATERIAL_H
