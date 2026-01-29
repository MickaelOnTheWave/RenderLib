#ifndef ENGINEENTITY_H
#define ENGINEENTITY_H

#include <string>
#include "scene/managers/ReferenceResourceManager.h"

class EngineEntity
{
template <class T>
friend class ReferenceResourceManager;

template <class T>
friend class ValueResourceManager;

public:
    EngineEntity(const std::string& _name);
    EngineEntity(const EngineEntity& other);

    EngineEntity& operator=(const EngineEntity& other);

    std::string GetName() const;
    unsigned int GetId() const;

private:
   std::string name;
   unsigned int id;
};

#endif // ENGINEENTITY_H
