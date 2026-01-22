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
   ResourceManager<Camera>::Add(newCamera);
   currentCamera = newCamera;
}
