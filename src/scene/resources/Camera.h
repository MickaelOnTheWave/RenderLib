#ifndef CAMERA_H
#define CAMERA_H

#include "EngineEntity.h"

#include "math/Matrix4x4.h"

class Camera : public EngineEntity
{
public:
   Camera(const std::string& _name);
   virtual ~Camera() = default;

private:
   Matrix4x4 transformMatrix;
   Matrix4x4 projectionMatrix;
};

#endif // CAMERA_H
