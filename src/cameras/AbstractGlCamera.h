#ifndef ABSTRACTGLCAMERA_H
#define ABSTRACTGLCAMERA_H

#include "math/Matrix4x4.h"

class AbstractGlCamera
{
public:
   AbstractGlCamera();
    virtual ~AbstractGlCamera() = default;

   Vector3 GetPosition() const;
   Vector3 GetDirection() const;
   Matrix4x4 GetTransformMatrix() const;
   Matrix4x4 GetProjectionMatrix() const;

   void SetPerspectiveProjection(const float fieldOfView, const float aspectRatio,
                                 const float nearZ, const float farZ);
   void SetOrthographicProjection(const float width, const float height,
                                  const float nearZ, const float farZ);

protected:
   Matrix4x4 transformMatrix;
   Matrix4x4 projectionMatrix;
};

#endif // ABSTRACTGLCAMERA_H
