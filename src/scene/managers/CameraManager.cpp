#include "CameraManager.h"

CameraManager::CameraManager()
   : currentCamera(nullptr)
{
}

Camera* CameraManager::GetCurrentCamera()
{
   return currentCamera;
}

void CameraManager::Add(Camera* newCamera)
{
   ReferenceResourceManager<Camera>::Add(newCamera);
   currentCamera = newCamera;
}
