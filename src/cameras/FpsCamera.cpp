#include "FpsCamera.h"

FpsCamera::FpsCamera(const Vector3 &startPosition)
{
   transformMatrix = Matrix4x4::Translation(startPosition * -1);
}

void FpsCamera::MoveInX(const double speed)
{
   transformMatrix *= Matrix4x4::Translation(Vector3(0, 0, -speed));
}

void FpsCamera::MoveInY(const double speed)
{
   transformMatrix *= Matrix4x4::Translation(Vector3(-speed, 0, 0));
}

void FpsCamera::RotateInX(const double angle)
{

}

void FpsCamera::RotateInY(const double angle)
{

}
