#ifndef LIGHT_H
#define LIGHT_H

#include "EngineEntity.h"

#include "math/Vector3.h"

class Light : public EngineEntity
{
public:
   Light(const std::string& _name);

   Vector3 position;
   Vector3 color;
};

#endif // LIGHT_H
