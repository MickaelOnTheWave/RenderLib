#ifndef MODELINSTANCE_H
#define MODELINSTANCE_H

#include "EngineEntity.h"

#include "math/Matrix4x4.h"

class ModelInstance : public EngineEntity
{
public:
   ModelInstance(const std::string& _name);

   unsigned int GetModelId() const;

   Matrix4x4 GetTransform() const;
   void SetTransform(const Matrix4x4& newTransform);

   Vector3 GetColor() const;
   void SetColor(const Vector3& _color);

private:
   unsigned int modelId;
   Matrix4x4 transform;
   Vector3 color;
};

#endif // MODELINSTANCE_H
