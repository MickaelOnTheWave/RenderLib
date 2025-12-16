#include "NamedEntity.h"

NamedEntity::NamedEntity(const std::string& _name)
    : name(_name)
{
}

NamedEntity::NamedEntity(const NamedEntity& other)
    : name(other.name)
{
}

std::string NamedEntity::GetName() const
{
    return name;
}
