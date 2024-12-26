#include "AbstractGlCamera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

AbstractGlCamera::AbstractGlCamera()
{
   const float fov = glm::radians(90.f);
   const glm::mat4 glmProjection = glm::perspective(fov, 800.f / 600.f, 0.1f, 100.f);
   projectionMatrix = Matrix4x4(glmProjection);
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

Matrix4x4 AbstractGlCamera::GetProjectionMatrix() const
{
   return projectionMatrix;
}
