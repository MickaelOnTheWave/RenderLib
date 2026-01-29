#include "ModelInstance.h"

ModelInstance::ModelInstance(const std::string& _name)
   : EngineEntity(_name)
{
}

unsigned int ModelInstance::GetModelId() const
{
   return modelId;
}

void ModelInstance::SetModelId(const unsigned int _modelId)
{
   modelId = _modelId;
}

Matrix4x4 ModelInstance::GetTransform() const
{
   return transform;
}

void ModelInstance::SetTransform(const Matrix4x4 &newTransform)
{
   transform = newTransform;
}

Vector3 ModelInstance::GetColor() const
{
   return color;
}

void ModelInstance::SetColor(const Vector3 &_color)
{
   color = _color;
}
