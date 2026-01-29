#include "Triangulator.h"

Triangulator::Triangulator() {}

TriangulatedData Triangulator::Triangulate(const Box& geometry)
{
   TriangulatedData data;

   const Vector3 center = geometry.GetCenter();
   const Vector3 radius = geometry.GetSizes() / 2.f;

   data.points.reserve(8);
   data.points.push_back(center + Vector3(-radius.X(), -radius.Y(),  radius.Z()));
   data.points.push_back(center + Vector3( radius.X(), -radius.Y(),  radius.Z()));
   data.points.push_back(center + Vector3( radius.X(),  radius.Y(),  radius.Z()));
   data.points.push_back(center + Vector3(-radius.X(),  radius.Y(),  radius.Z()));

   data.points.push_back(center + Vector3(-radius.X(), -radius.Y(), -radius.Z()));
   data.points.push_back(center + Vector3( radius.X(), -radius.Y(), -radius.Z()));
   data.points.push_back(center + Vector3( radius.X(),  radius.Y(), -radius.Z()));
   data.points.push_back(center + Vector3(-radius.X(),  radius.Y(), -radius.Z()));

   data.faces.reserve(12);

   TriangulatedFaceData frontFace1;
   frontFace1.vertexIndices = {0, 1, 2};
   frontFace1.normal = Vector3(0.f, 0.f, 1.f);
   data.faces.push_back(frontFace1);

   TriangulatedFaceData frontFace2;
   frontFace2.vertexIndices = {2, 3, 0};
   frontFace2.normal = Vector3(0.f, 0.f, 1.f);
   data.faces.push_back(frontFace2);

   TriangulatedFaceData rightFace1;
   rightFace1.vertexIndices = {1, 5, 6};
   rightFace1.normal = Vector3(1.f, 0.f, 0.f);
   data.faces.push_back(rightFace1);

   TriangulatedFaceData rightFace2;
   rightFace2.vertexIndices = {6, 2, 1};
   rightFace2.normal = Vector3(1.f, 0.f, 0.f);
   data.faces.push_back(rightFace2);

   TriangulatedFaceData backFace1;
   backFace1.vertexIndices = {5, 4, 7};
   backFace1.normal = Vector3(0.f, 0.f, -1.f);
   data.faces.push_back(backFace1);

   TriangulatedFaceData backFace2;
   backFace2.vertexIndices = {7, 6, 5};
   backFace2.normal = Vector3(0.f, 0.f, -1.f);
   data.faces.push_back(backFace2);

   TriangulatedFaceData leftFace1;
   leftFace1.vertexIndices = {4, 0, 3};
   leftFace1.normal = Vector3(-1.f, 0.f, 0.f);
   data.faces.push_back(leftFace1);

   TriangulatedFaceData leftFace2;
   leftFace2.vertexIndices = {3, 7, 4};
   leftFace2.normal = Vector3(-1.f, 0.f, 0.f);
   data.faces.push_back(leftFace2);

   TriangulatedFaceData bottomFace1;
   bottomFace1.vertexIndices = {4, 5, 1};
   bottomFace1.normal = Vector3(0.f, -1.f, 0.f);
   data.faces.push_back(bottomFace1);

   TriangulatedFaceData bottomFace2;
   bottomFace2.vertexIndices = {1, 0, 4};
   bottomFace2.normal = Vector3(0.f, -1.f, 0.f);
   data.faces.push_back(bottomFace2);

   TriangulatedFaceData topFace1;
   topFace1.vertexIndices = {3, 2, 6};
   topFace1.normal = Vector3(0.f, 1.f, 0.f);
   data.faces.push_back(topFace1);

   TriangulatedFaceData topFace2;
   topFace2.vertexIndices = {6, 7, 3};
   topFace2.normal = Vector3(0.f, 1.f, 0.f);
   data.faces.push_back(topFace2);


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
