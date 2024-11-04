#include "OrbitCamera.h"

OrbitCamera::OrbitCamera(const float _targetX, const float _targetY, const float _targetZ)
   : AbstractGlCamera(),
     targetX(_targetX), targetY(_targetY), targetZ(_targetZ)
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
   transformMatrix = Matrix4x4::Translation(-targetX, -targetY, -targetZ) * Matrix4x4::RotationX(currentAngleX) *
                     Matrix4x4::RotationY(currentAngleY);
}
