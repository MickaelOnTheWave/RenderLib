#include "GlRenderSphereOctahedron.h"

void GlRenderSphereOctahedron::PopulateInitialGeometry()
{
   const GLfloat radius = 1.f;

   // Initial points
   points.emplace_back(0.f, radius, 0.f);
   points.emplace_back(0.f, 0.f, -radius);
   points.emplace_back(0.f, -radius, 0.f);
   points.emplace_back(0.f, radius, 0.f);
   points.emplace_back(radius, 0.f, 0.f);
   points.emplace_back(0.f, -radius, 0.f);
   points.emplace_back(0.f, radius, 0.f);
   points.emplace_back(0.f, 0.f, radius);
   points.emplace_back(0.f, -radius, 0.f);
   points.emplace_back(0.f, radius, 0.f);
   points.emplace_back(-radius, 0.f, 0.f);
   points.emplace_back(0.f, -radius, 0.f);
   points.emplace_back(0.f, radius, 0.f);
   points.emplace_back(0.f, 0.f, -radius);
   points.emplace_back(0.f, -radius, 0.f);

   for (int i=0; i<15; ++i)
      colors.emplace_back(1.f, 1.f, 1.f);

   textureCoordinates.emplace_back(1.f, 1.f);
   textureCoordinates.emplace_back(1.f, 0.5f);
   textureCoordinates.emplace_back(1.f, 0.f);
   textureCoordinates.emplace_back(0.75f, 1.f);
   textureCoordinates.emplace_back(0.75f, 0.5f);
   textureCoordinates.emplace_back(0.75f, 0.f);
   textureCoordinates.emplace_back(0.5f, 1.f);
   textureCoordinates.emplace_back(0.5f, 0.5f);
   textureCoordinates.emplace_back(0.5f, 0.f);
   textureCoordinates.emplace_back(0.25f, 1.f);
   textureCoordinates.emplace_back(0.25f, 0.5f);
   textureCoordinates.emplace_back(0.25f, 0.f);
   textureCoordinates.emplace_back(0.f, 1.f);
   textureCoordinates.emplace_back(0.f, 0.5f);
   textureCoordinates.emplace_back(0.f, 0.f);

   // Initial triangles
   triangles.emplace_back(0, 4, 1);
   triangles.emplace_back(1, 4, 2);
   triangles.emplace_back(3, 7, 4);
   triangles.emplace_back(4, 7, 5);
   triangles.emplace_back(6, 10, 7);
   triangles.emplace_back(7, 10, 8);
   triangles.emplace_back(9, 13, 10);
   triangles.emplace_back(10, 13, 11);
}
