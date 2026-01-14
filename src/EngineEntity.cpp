#include "EngineEntity.h"

EngineEntity::EngineEntity(const std::string& _name)
   : name(_name), id(0)
{
}

EngineEntity::EngineEntity(const EngineEntity& other)
   : name(other.name), id(other.id)
{
}

EngineEntity& EngineEntity::operator=(const EngineEntity& other)
{
   name = other.name;
   id = other.id;
   return *this;
}

std::string EngineEntity::GetName() const
{
   return name;
}

unsigned int EngineEntity::GetId() const
{
   return id;
}
