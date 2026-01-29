#ifndef TRIANGULATOR_H
#define TRIANGULATOR_H

#include <array>
#include "Box.h"
#include "Cylinder.h"
#include "Plane.h"
#include "Sphere.h"

struct AdjacencyData
{
   std::vector<unsigned int> adjacentVertexIndices;
   std::vector<unsigned int> adjacentFaceIndices;
};

struct TriangulatedFaceData
{
   // 3 points per triangle
   std::array<unsigned int, 3> vertexIndices;
   Vector3 normal;
};

struct TriangulatedData
{
   std::vector<Vector3> points;
   std::vector<TriangulatedFaceData> faces;
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
