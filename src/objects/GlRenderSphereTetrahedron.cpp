#include "GlRenderSphereTetrahedron.h"

#include <math.h>

void GlRenderSphereTetrahedron::PopulateInitialGeometry()
{
   const GLfloat radius = 1.f;
   const float angle = M_PI / 6.f;
   //const float angle = 2 * M_PI / 3.f;
   const GLfloat cosAngle = cos(angle);
   const GLfloat sinAngle = sin(angle);

   // Initial points
   points.emplace_back(0.f, radius, 0.f);
   points.emplace_back(0.f, -sinAngle, -cosAngle);
   points.emplace_back(cosAngle* cosAngle, -sinAngle, cosAngle * cosAngle);
   points.emplace_back(-cosAngle* cosAngle, -sinAngle, cosAngle * cosAngle);

   colors.emplace_back(0.f, 1.f, 0.f);
   colors.emplace_back(0.f, 0.f, 1.f);
   colors.emplace_back(1.f, 0.f, 0.f);
   colors.emplace_back(1.f, 0.f, 0.f);

   textureCoordinates.emplace_back(0.5f, 1.f);
   textureCoordinates.emplace_back(0.f, 0.f);
   textureCoordinates.emplace_back(1.f, 0.f);
   textureCoordinates.emplace_back(0.f, 0.f);

   // Initial triangles
   triangles.emplace_back(0, 2, 3);
   triangles.emplace_back(0, 1, 2);
   triangles.emplace_back(0, 3, 1);
   triangles.emplace_back(3, 2, 1);
}
