#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "ReferenceResourceManager.h"

#include "scene/resources/Camera.h"

class CameraManager : public ReferenceResourceManager<Camera>
{
public:
   CameraManager();

   Camera* GetCurrentCamera();

   unsigned int Add(Camera* newCamera);

private:
   Camera* currentCamera;
};

#endif // CAMERAMANAGER_H
