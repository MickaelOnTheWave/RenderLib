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

protected:
   Matrix4x4 transformMatrix;
   Matrix4x4 projectionMatrix;
};

#endif // ABSTRACTGLCAMERA_H
