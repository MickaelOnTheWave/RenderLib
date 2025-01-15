#ifndef FPSCAMERA_H
#define FPSCAMERA_H

#include "AbstractGlCamera.h"

class FpsCamera : public AbstractGlCamera
{
public:
   FpsCamera(const Vector3& startPosition);

   Vector3 GetPosition() const override;
   Vector3 GetDirection() const override;
   Vector3 GetUpVector() const override;


   void MoveInX(const double speed);
   void MoveInY(const double speed);
   void RotateHorizontal(const double angle);
   void RotateVertical(const double angle);

};

#endif // FPSCAMERA_H
