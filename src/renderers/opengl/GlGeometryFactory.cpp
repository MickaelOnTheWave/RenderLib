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
   std::unique_ptr<GlGeometry> glGeometry;
   if (auto typedGeometry = dynamic_cast<Box*>(sceneGeometry))
   {
      const TriangulatedData data = Triangulator::Triangulate(*typedGeometry);
      glGeometry = std::make_unique<GlTriangulatedGeometry>(data);
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
   glGeometry->sceneId = sceneGeometry->GetId();
   glGeometry->Initialize();
   return glGeometry;
}
