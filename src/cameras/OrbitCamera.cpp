#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(const Vector3 &_target)
   : AbstractGlCamera(),
  target(_target)
{
   rotationSpeed = 0.01f;
}

void OrbitCamera::RotateInX(const double angle)
{
   currentAngleX += angle * rotationSpeed;
   updateTransformMatrix();
}

void OrbitCamera::RotateInY(const double angle)
{
   currentAngleY += angle * rotationSpeed;
   updateTransformMatrix();
}

void OrbitCamera::updateTransformMatrix(void)
{
   transformMatrix = Matrix4x4::Translation(-target.X(), -target.Y(), -target.Z()) * Matrix4x4::RotationX(currentAngleX) *
                     Matrix4x4::RotationY(currentAngleY);
}
