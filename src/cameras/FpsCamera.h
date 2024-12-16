#ifndef FPSCAMERA_H
#define FPSCAMERA_H

#include "AbstractGlCamera.h"

class FpsCamera : public AbstractGlCamera
{
public:
   FpsCamera(const Vector3& startPosition);

   void MoveInX(const double speed);
   void MoveInY(const double speed);
   void RotateInX(const double angle);
   void RotateInY(const double angle);

};

#endif // FPSCAMERA_H