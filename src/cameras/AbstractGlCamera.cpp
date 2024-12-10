#include "AbstractGlCamera.h"

AbstractGlCamera::AbstractGlCamera()
{
}

Vector3 AbstractGlCamera::GetPosition() const
{
   return Vector3(transformMatrix[12], transformMatrix[13], transformMatrix[14]);
}

Vector3 AbstractGlCamera::GetDirection() const
{
   return Vector3(transformMatrix[0], transformMatrix[5], transformMatrix[10]);
}

Matrix4x4 AbstractGlCamera::GetTransformMatrix() const
{
   return transformMatrix;
}
