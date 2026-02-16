#include "Camera.h"

Camera::Camera(const std::string& _name)
   : EngineEntity(_name)
{
}

Matrix4x4 Camera::GetViewProjectionMatrix() const
{
   return projectionMatrix * viewMatrix;
}

float Camera::ToRadians(const float angleInDegrees) const
{
   return angleInDegrees * (M_PI / 180.f);
}

void Camera::SetPerspectiveProjection(const float fieldOfViewYInRadians, const float aspectRatio, const float nearPlaneZ, const float farPlaneZ)
{
   projectionMatrix = Matrix4x4::Identity();

   const float tanHalfFieldOfView = tan(fieldOfViewYInRadians * 0.5f);

   projectionMatrix[0] = 1.f / (aspectRatio * tanHalfFieldOfView);
   projectionMatrix[5] = 1.f / tanHalfFieldOfView;
   projectionMatrix[10] = (nearPlaneZ + farPlaneZ) / (nearPlaneZ - farPlaneZ);
   projectionMatrix[11] = (2.f * nearPlaneZ * farPlaneZ) / (nearPlaneZ - farPlaneZ);
   projectionMatrix[14] = -1.f;
}

void Camera::SetPerspectiveProjectionDegrees(const float fieldOfViewY, const float aspectRatio, const float nearPlaneZ, const float farPlaneZ)
{
   SetPerspectiveProjection(ToRadians(fieldOfViewY), aspectRatio, nearPlaneZ, farPlaneZ);
}

void Camera::LookAt(const Vector3& eye, const Vector3& target, const Vector3& up)
{
   viewMatrix = Matrix4x4::Identity();

   const Vector3 forwardDir = (target - eye).Normalized();
   const Vector3 rightDir = forwardDir.CrossProduct(up).Normalized();
   const Vector3 upDir = rightDir.CrossProduct(forwardDir);

   viewMatrix[0] = rightDir.X();
   viewMatrix[1] = upDir.X();
   viewMatrix[2] = forwardDir.X() * -1.f;
   viewMatrix[3] = 0.f;
   viewMatrix[4] = rightDir.Y();
   viewMatrix[5] = upDir.Y();
   viewMatrix[6] = forwardDir.Y() * -1.f;
   viewMatrix[7] = 0.f;
   viewMatrix[8] = rightDir.Z();
   viewMatrix[9] = upDir.Z();
   viewMatrix[10] = forwardDir.Z() * -1.f;
   viewMatrix[11] = 0.f;
   viewMatrix[12] = rightDir.DotProduct(eye) * -1.f;
   viewMatrix[13] = upDir.DotProduct(eye) * -1.f;
   viewMatrix[14] = forwardDir.DotProduct(eye);
   viewMatrix[15] = 1.f;
}
