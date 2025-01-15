#ifndef ORBITCAMERA_H
#define ORBITCAMERA_H

#include "AbstractGlCamera.h"

class OrbitCamera : public AbstractGlCamera
{
public:
   OrbitCamera(const Vector3& _target);

   Vector3 GetPosition() const override;
   Vector3 GetDirection() const override;
   Vector3 GetUpVector() const override;

   void RotateInX(const double angle);
   void RotateInY(const double angle);
   void CloseIn(const double speed);
   void CloseOut(const double speed);

private:
   void updateTransformMatrix(void);

   Vector3 target;
   float targetX, targetY, targetZ;
   float rotationSpeed;
   float currentAngleX = 0.f;
   float currentAngleY = 0.f;
   float distance = -2.f;
};

#endif // ORBITCAMERA_H
