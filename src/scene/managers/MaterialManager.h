#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include "scene/resources/Material.h"
#include "ValueResourceManager.h"

class MaterialManager : public ValueResourceManager<Material>
{
public:
   MaterialManager() = default;
   virtual ~MaterialManager() = default;
};

#endif // MATERIALMANAGER_H
