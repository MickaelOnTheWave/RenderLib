#include "GlCamera.h"

GlCamera::GlCamera()
   : AbstractGlCamera()
{
}

void GlCamera::moveTo(double x, double y)
{
   const float scaleFactor = 1000.f;
   transformMatrix = Matrix4x4::Translation(
                        x/scaleFactor, y/scaleFactor, 0.f);
}

void GlCamera::rotateAroundX(const double angle)
{
   const float scaleFactor = 0.002f;
   const float scaledAngle = angle * scaleFactor;
   transformMatrix = transformMatrix * Matrix4x4::RotationX(scaledAngle);
}

void GlCamera::rotateAroundY(const double angle)
{
   const float scaleFactor = 0.002f;
   transformMatrix = transformMatrix * Matrix4x4::RotationY(angle * scaleFactor);
}
