#ifndef MATERIAL_H
#define MATERIAL_H

#include "EngineEntity.h"

#include <string>

class Material : public EngineEntity
{
public:
   Material(const std::string& _name);
   Material(const Material& other);

   unsigned int diffuseTextureId;
   unsigned int specularTextureId;
   float shininess;
};

#endif // MATERIAL_H
