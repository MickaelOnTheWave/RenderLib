#ifndef ORBITCAMERA_H
#define ORBITCAMERA_H

#include "AbstractGlCamera.h"

class OrbitCamera : public AbstractGlCamera
{
public:
   OrbitCamera(const float _targetX,
               const float _targetY,
               const float _targetZ);

   void RotateInX(const double angle);
   void RotateInY(const double angle);

private:
   void updateTransformMatrix(void);

   float targetX, targetY, targetZ;
   float rotationSpeed;
   float currentAngleX = 0.f;
   float currentAngleY = 0.f;
};

#endif // ORBITCAMERA_H
