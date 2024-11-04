#ifndef GLCAMERA_H
#define GLCAMERA_H

#include "AbstractGlCamera.h"

class GlCamera : public AbstractGlCamera
{
public:
   GlCamera();

   void moveTo(double x, double y);
   void rotateAroundX(const double angle);
   void rotateAroundY(const double angle);
};

#endif // GLCAMERA_H
