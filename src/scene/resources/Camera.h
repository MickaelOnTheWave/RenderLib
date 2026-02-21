#ifndef CAMERA_H
#define CAMERA_H

#include "EngineEntity.h"

#include "math/Angle.h"
#include "math/Matrix4x4.h"

class Camera : public EngineEntity
{
public:
   Camera(const std::string& _name);
   virtual ~Camera() = default;

   void SetPerspectiveProjection(const Angle fieldOfViewY,
                                 const float aspectRatio,
                                 const float nearPlaneZ = 0.1f,
                                 const float farPlaneZ = 1000.f);

   void LookAt(const Vector3& eye, const Vector3& target,
               const Vector3& up = Vector3(0.f, 1.f, 0.f));

   Matrix4x4 GetViewProjectionMatrix() const;

private:
   float ToRadians(const float angleInDegrees) const;

   Matrix4x4 viewMatrix;
   Matrix4x4 projectionMatrix;
};

#endif // CAMERA_H
