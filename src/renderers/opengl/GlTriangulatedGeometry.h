#ifndef GLTRIANGULATEDGEOMETRY_H
#define GLTRIANGULATEDGEOMETRY_H

#include "GlGeometry.h"

#include <vector>
#include "math/Vector3.h"

class GlTriangulatedGeometry : public GlGeometry
{
public:
   GlTriangulatedGeometry();

   std::vector<Vector3> points;
   std::vector<Vector3> normals;
};

#endif // GLTRIANGULATEDGEOMETRY_H
