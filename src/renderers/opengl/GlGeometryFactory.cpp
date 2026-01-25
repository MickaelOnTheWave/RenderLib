#include "GlGeometryFactory.h"

#include "GlTriangulatedGeometry.h"
#include "scene/resources/geometries/Box.h"
#include "scene/resources/geometries/Cylinder.h"
#include "scene/resources/geometries/Mesh.h"
#include "scene/resources/geometries/Plane.h"
#include "scene/resources/geometries/Sphere.h"
#include "scene/resources/geometries/Triangulator.h"

std::unique_ptr<GlGeometry> GlGeometryFactory::Create(Geometry* sceneGeometry)
{
   if (auto typedGeometry = dynamic_cast<Box*>(sceneGeometry))
   {
      const TriangulatedData data = Triangulator::Triangulate(*typedGeometry);
      auto glGeometry = std::make_unique<GlTriangulatedGeometry>(data);
      glGeometry->sceneId = typedGeometry->GetId();
      return glGeometry;
   }
   else if (auto typedGeometry = dynamic_cast<Cylinder*>(sceneGeometry))
   {

   }
   else if (auto typedGeometry = dynamic_cast<Mesh*>(sceneGeometry))
   {

   }
   else if (auto typedGeometry = dynamic_cast<Plane*>(sceneGeometry))
   {

   }
   else if (auto typedGeometry = dynamic_cast<Sphere*>(sceneGeometry))
   {

   }
   return nullptr;
}
