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
   return Vector3(transformMatrix[2], transformMatrix[6], transformMatrix[10]) * distance * -1.0;
}

Vector3 OrbitCamera::GetDirection() const
{
   const Vector3 rightVector = Vector3(transformMatrix[0], transformMatrix[4], transformMatrix[8]);
   return rightVector.CrossProduct(GetUpVector()) * -1;
}

Vector3 OrbitCamera::GetUpVector() const
{
   return Vector3(transformMatrix[1], transformMatrix[5], transformMatrix[9]);
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
   updateTransformMatrix();
}

void OrbitCamera::CloseOut(const double speed)
{
   distance += 0.5 * speed;
   updateTransformMatrix();
}

void OrbitCamera::updateTransformMatrix(void)
{
   transformMatrix = Matrix4x4::Translation(target * -1) * Matrix4x4::RotationX(currentAngleX) *
                     Matrix4x4::RotationY(currentAngleY) * Matrix4x4::Translation(0.f, 0.f, distance);
}
