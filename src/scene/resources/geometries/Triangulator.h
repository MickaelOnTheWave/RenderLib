#ifndef TRIANGULATOR_H
#define TRIANGULATOR_H

#include "Box.h"
#include "Cylinder.h"
#include "Plane.h"
#include "Sphere.h"

struct AdjacencyData
{
   std::vector<unsigned int> adjacentVertexIndices;
   std::vector<unsigned int> adjacentFaceIndices;
};

struct TriangulatedData
{
   std::vector<Vector3> points;
   std::vector<unsigned int> faceIndices;
   std::vector<Vector3> faceNormals;
   std::vector<AdjacencyData> adjacencyData;
};

class Triangulator
{
public:
   Triangulator();

   static TriangulatedData Triangulate(const Box& geometry);
   static TriangulatedData Triangulate(const Cylinder& geometry);
   static TriangulatedData Triangulate(const Plane& geometry);
   static TriangulatedData Triangulate(const Sphere& geometry);
};

#endif // TRIANGULATOR_H
