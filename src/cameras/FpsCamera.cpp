#include "FpsCamera.h"

FpsCamera::FpsCamera(const Vector3 &startPosition)
{
   transformMatrix = Matrix4x4::Translation(startPosition * -1);

   // Defaults to perspective projection
   SetPerspectiveProjection(90.f, 800.f / 600.f, 0.1f, 500.f);
}

Vector3 FpsCamera::GetPosition() const
{
   return Vector3(transformMatrix[2], transformMatrix[6], transformMatrix[10]);
}

Vector3 FpsCamera::GetDirection() const
{
   const Vector3 rightVector = Vector3(transformMatrix[0], transformMatrix[4], transformMatrix[8]);
   return rightVector.CrossProduct(GetUpVector()) * -1;
}

Vector3 FpsCamera::GetUpVector() const
{
   return Vector3(transformMatrix[1], transformMatrix[5], transformMatrix[9]);
}


void FpsCamera::MoveInX(const double speed)
{
   transformMatrix *= Matrix4x4::Translation(Vector3(0, 0, speed));
}

void FpsCamera::MoveInY(const double speed)
{
   transformMatrix *= Matrix4x4::Translation(Vector3(-speed, 0, 0));
}

void FpsCamera::RotateHorizontal(const double angle)
{
   transformMatrix *= Matrix4x4::RotationY(angle);
}

void FpsCamera::RotateVertical(const double angle)
{
   transformMatrix *= Matrix4x4::RotationX(angle);
}
