#ifndef MODEL_H
#define MODEL_H

#include "EngineEntity.h"

#include <vector>

class Model : public EngineEntity
{
public:
   Model(const std::string& _name);

private:
   struct ModelPart
   {
      unsigned int geometryId;
      unsigned int materialId;
   };

   std::vector<ModelPart> parts;
};

#endif // MODEL_H
