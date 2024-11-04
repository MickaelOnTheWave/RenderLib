#ifndef ABSTRACTGLCAMERA_H
#define ABSTRACTGLCAMERA_H

#include "math/Matrix4x4.h"

// TODO Implement FPS Camera
class AbstractGlCamera
{
public:
   AbstractGlCamera();

   Matrix4x4 getTransformMatrix();

protected:
   Matrix4x4 transformMatrix;
};

#endif // ABSTRACTGLCAMERA_H
