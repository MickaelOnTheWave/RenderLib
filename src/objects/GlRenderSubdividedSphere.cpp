#include "GlRenderSubdividedSphere.h"

using namespace std;

void GlRenderSubdividedSphere::PopulateGeometry(const unsigned int subdivisions)
{
   PopulateInitialGeometry();

   for (unsigned int currentDivision = 0; currentDivision < subdivisions; ++currentDivision)
   {
      // TODO create list of pointers to iterate from.
      // Subdivide removes triangles, and thus the indexes are skewed.
      const unsigned int triangleCount = triangles.size();
      for (unsigned int i=0; i<triangleCount; ++i)
      {
         list<Triangle>::iterator itTriangle = triangles.begin();
         itTriangle->Subdivide(points, textureCoordinates, triangles, itTriangle);
      }
   }
}
