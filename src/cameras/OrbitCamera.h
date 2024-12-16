#ifndef ORBITCAMERA_H
#define ORBITCAMERA_H

#include "AbstractGlCamera.h"

class OrbitCamera : public AbstractGlCamera
{
public:
   OrbitCamera(const Vector3& _target);

   void RotateInX(const double angle);
   void RotateInY(const double angle);

private:
   void updateTransformMatrix(void);

   Vector3 target;
   float targetX, targetY, targetZ;
   float rotationSpeed;
   float currentAngleX = 0.f;
   float currentAngleY = 0.f;
};

#endif // ORBITCAMERA_H
