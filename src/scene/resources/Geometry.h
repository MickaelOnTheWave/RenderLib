#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "EngineEntity.h"

class Geometry : public EngineEntity
{
public:
   Geometry(const std::string& _name);
   virtual ~Geometry() = default;
};

#endif // GEOMETRY_H
