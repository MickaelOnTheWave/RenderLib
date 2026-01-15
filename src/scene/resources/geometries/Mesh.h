#ifndef MESH_H
#define MESH_H

#include "scene/resources/Geometry.h"

#include <vector>
#include "math/Vector3.h"

class Mesh : public Geometry
{
public:
   Mesh();

private:
   using Face = std::vector<unsigned int>; // indices into vertices
   std::vector<Vector3> vertices;
   std::vector<Face> faces;
};

#endif // MESH_H
