#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include "scene/resources/Material.h"
#include "ResourceManager.h"

class MaterialManager : public ResourceManager<Material>
{
public:
   MaterialManager() = default;
   virtual ~MaterialManager() = default;
};

#endif // MATERIALMANAGER_H
