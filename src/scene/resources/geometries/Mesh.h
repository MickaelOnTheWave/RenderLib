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
   using FaceIndices = std::vector<unsigned int>;
   std::vector<Vector3> vertices;
   std::vector<FaceIndices> faces;
};

#endif // MESH_H

