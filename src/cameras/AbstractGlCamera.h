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

protected:
   Matrix4x4 transformMatrix;
};

#endif // ABSTRACTGLCAMERA_H
