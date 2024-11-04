#include "AbstractGlCamera.h"

AbstractGlCamera::AbstractGlCamera()
{
}

Matrix4x4 AbstractGlCamera::getTransformMatrix()
{
   return transformMatrix;
}
