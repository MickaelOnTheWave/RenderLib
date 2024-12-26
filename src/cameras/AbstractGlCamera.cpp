#include "AbstractGlCamera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

Matrix4x4 AbstractGlCamera::GetProjectionMatrix() const
{
   return projectionMatrix;
}

void AbstractGlCamera::SetPerspectiveProjection(const float fieldOfView, const float aspectRatio, const float nearZ, const float farZ)
{
   const float fovInRadians = glm::radians(fieldOfView);
   const glm::mat4 glmProjection = glm::perspective(fovInRadians, 800.f / 600.f, nearZ, farZ);
   projectionMatrix = Matrix4x4(glmProjection);
}

void AbstractGlCamera::SetOrthographicProjection(const float width, const float height, const float nearZ, const float farZ)
{
   const glm::mat4 glmProjection = glm::ortho(0.f, width, 0.f, height, nearZ, farZ);
   projectionMatrix = Matrix4x4(glmProjection);
}

