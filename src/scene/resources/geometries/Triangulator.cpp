#include "Triangulator.h"

Triangulator::Triangulator() {}

TriangulatedData Triangulator::Triangulate(const Box& geometry)
{
   TriangulatedData data;

   const Vector3 center = geometry.GetCenter();
   const Vector3 radius = geometry.GetSizes() / 2.f;

   data.points.push_back(center + Vector3(-radius.X(), -radius.Y(),  radius.Z()));
   data.points.push_back(center + Vector3( radius.X(), -radius.Y(),  radius.Z()));
   data.points.push_back(center + Vector3( radius.X(),  radius.Y(),  radius.Z()));
   data.points.push_back(center + Vector3(-radius.X(),  radius.Y(),  radius.Z()));

   data.points.push_back(center + Vector3(-radius.X(), -radius.Y(), -radius.Z()));
   data.points.push_back(center + Vector3( radius.X(), -radius.Y(), -radius.Z()));
   data.points.push_back(center + Vector3( radius.X(),  radius.Y(), -radius.Z()));
   data.points.push_back(center + Vector3(-radius.X(),  radius.Y(), -radius.Z()));

   data.faceIndices = {
      // Front face (Z+)
      0, 1, 2,  2, 3, 0,
      // Right face (X+)
      1, 5, 6,  6, 2, 1,
      // Back face (Z-)
      5, 4, 7,  7, 6, 5,
      // Left face (X-)
      4, 0, 3,  3, 7, 4,
      // Bottom face (Y-)
      4, 5, 1,  1, 0, 4,
      // Top face (Y+)
      3, 2, 6,  6, 7, 3
   };

   data.faceNormals = {
      Vector3(0.f, 0.f, 1.f),   // Front face (Z+)
      Vector3(1.f, 0.f, 0.f),   // Right face (X+)
      Vector3(0.f, 0.f, -1.f),  // Back face (Z-)
      Vector3(-1.f, 0.f, 0.f),  // Left face (X-)
      Vector3(0.f, -1.f, 0.f),  // Bottom face (Y-)
      Vector3(0.f, 1.f, 0.f)    // Top face (Y+)
   };

   data.adjacencyData.resize(8); // 8 vertices

   // Vertex 0 (front-bottom-left)
   data.adjacencyData[0].adjacentVertexIndices = {1, 3, 4};
   data.adjacencyData[0].adjacentFaceIndices = {0, 4, 5}; // Faces: front, bottom, left

   // Vertex 1 (front-bottom-right)
   data.adjacencyData[1].adjacentVertexIndices = {0, 2, 5};
   data.adjacencyData[1].adjacentFaceIndices = {0, 1, 4}; // Faces: front, right, bottom

   // Vertex 2 (front-top-right)
   data.adjacencyData[2].adjacentVertexIndices = {1, 3, 6};
   data.adjacencyData[2].adjacentFaceIndices = {0, 1, 2}; // Faces: front, right, top

   // Vertex 3 (front-top-left)
   data.adjacencyData[3].adjacentVertexIndices = {0, 2, 7};
   data.adjacencyData[3].adjacentFaceIndices = {0, 2, 3}; // Faces: front, top, left

   // Vertex 4 (back-bottom-left)
   data.adjacencyData[4].adjacentVertexIndices = {0, 5, 7};
   data.adjacencyData[4].adjacentFaceIndices = {2, 3, 4}; // Faces: back, left, bottom

   // Vertex 5 (back-bottom-right)
   data.adjacencyData[5].adjacentVertexIndices = {1, 4, 6};
   data.adjacencyData[5].adjacentFaceIndices = {1, 2, 4}; // Faces: right, back, bottom

   return data;
}

TriangulatedData Triangulator::Triangulate(const Cylinder& geometry)
{
   TriangulatedData data;
   return data;
}

TriangulatedData Triangulator::Triangulate(const Plane& geometry)
{
   TriangulatedData data;
   return data;
}

TriangulatedData Triangulator::Triangulate(const Sphere& geometry)
{
   TriangulatedData data;
   return data;
}
