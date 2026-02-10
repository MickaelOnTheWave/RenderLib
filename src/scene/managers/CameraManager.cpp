#include "CameraManager.h"

CameraManager::CameraManager()
   : currentCamera(nullptr)
{
}

Camera* CameraManager::GetCurrentCamera() const
{
   return currentCamera;
}

unsigned int CameraManager::Add(Camera* newCamera)
{
   const unsigned int id = ReferenceResourceManager<Camera>::Add(newCamera);
   currentCamera = newCamera;
   return id;
}
