#include "FpsCamera.h"

FpsCamera::FpsCamera(const Vector3 &startPosition)
{
   transformMatrix = Matrix4x4::Translation(startPosition * -1);
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
   const Matrix4x4 minusPositionMat = Matrix4x4::Translation(GetPosition() * -1);
   //transformMatrix *= minusPositionMat;
   transformMatrix *= Matrix4x4::RotationY(angle);
}

void FpsCamera::RotateVertical(const double angle)
{
   /*const Matrix4x4 positionMat = Matrix4x4::Translation(GetPosition());
   const Matrix4x4 minusPositionMat = Matrix4x4::Translation(GetPosition() * -1);
   transformMatrix *= minusPositionMat;
   transformMatrix *= Matrix4x4::RotationX(angle);
   transformMatrix *= positionMat;*/


}
