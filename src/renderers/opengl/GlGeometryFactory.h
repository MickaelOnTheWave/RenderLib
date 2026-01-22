#ifndef GLGEOMETRYFACTORY_H
#define GLGEOMETRYFACTORY_H

#include <memory>

#include "scene/resources/Geometry.h"
#include "GlGeometry.h"

class GlGeometryFactory
{
public:
   GlGeometryFactory() = delete;
   ~GlGeometryFactory() = delete;

   static std::unique_ptr<GlGeometry> Create(Geometry* sceneGeometry);
};

#endif // GLGEOMETRYFACTORY_H
