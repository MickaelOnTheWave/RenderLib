#ifndef MODELINSTANCE_H
#define MODELINSTANCE_H

#include "EngineEntity.h"

#include "math/Matrix4x4.h"

class ModelInstance : public EngineEntity
{
public:
   ModelInstance(const std::string& _name);

   unsigned int modelId;
   Matrix4x4 transform;
};

#endif // MODELINSTANCE_H
