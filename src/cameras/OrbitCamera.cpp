#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(const Vector3 &_target)
   : AbstractGlCamera(),
  target(_target)
{
   rotationSpeed = 0.01f;

   //SetOrthographicProjection(800.f, 600.f, 0.1f, 500.f);
   SetPerspectiveProjection(90.f, 800.f / 600.f, 0.1f, 500.f);
   //projectionMatrix = Matrix4x4::Identity();
}

Vector3 OrbitCamera::GetPosition() const
{
   const Vector3 initialPosition(0.f, 0.f, 1.f);
   const Vector3 finalPos = initialPosition + target + Vector3(0.f, 0.f, -distance);
   return Matrix4x4::RotationX(currentAngleX) *
          Matrix4x4::RotationY(currentAngleY) * finalPos;
}

Vector3 OrbitCamera::GetDirection() const
{
   const Vector3 initialDirection(0.f, 0.f, -1.f);
   return transformMatrix * initialDirection;
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

void OrbitCamera::CloseIn(const double speed)
{
   distance -= 0.5 * speed;
}

void OrbitCamera::CloseOut(const double speed)
{
   distance += 0.5 * speed;
}

void OrbitCamera::updateTransformMatrix(void)
{
   transformMatrix = Matrix4x4::Translation(target * -1) * Matrix4x4::RotationX(currentAngleX) *
                     Matrix4x4::RotationY(currentAngleY) * Matrix4x4::Translation(0.f, 0.f, distance);
}
