#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(const Vector3 &_target)
   : AbstractGlCamera(),
  target(_target)
{
   rotationSpeed = 0.01f;

   //SetOrthographicProjection(800.f, 600.f, 0.1f, 500.f);
   projectionMatrix = Matrix4x4::Identity();
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

void OrbitCamera::ZoomIn(const double speed)
{
}

void OrbitCamera::ZoomOut(const double speed)
{

}

void OrbitCamera::updateTransformMatrix(void)
{
   transformMatrix = Matrix4x4::Translation(target * -1) * Matrix4x4::RotationX(currentAngleX) *
                     Matrix4x4::RotationY(currentAngleY);
}
