#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "ResourceManager.h"

#include "scene/resources/Camera.h"

class CameraManager : public ResourceManager<Camera>
{
public:
   CameraManager();

   Camera* GetCurrentCamera();

   void Add(Camera* newCamera);

private:
   Camera* currentCamera;
};

#endif // CAMERAMANAGER_H
