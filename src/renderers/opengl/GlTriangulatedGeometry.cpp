#include "GlTriangulatedGeometry.h"

GlTriangulatedGeometry::GlTriangulatedGeometry(const TriangulatedData& data)
{
   CreateWithFaceNormals(data);
}

std::vector<float> GlTriangulatedGeometry::CreateVertexBufferData() const
{
   return verticesNormalsUVs;
}

std::vector<unsigned int> GlTriangulatedGeometry::CreateIndexData() const
{
   return faceIndices;
}

void GlTriangulatedGeometry::CreateWithFaceNormals(const TriangulatedData& data)
{
   // Duplicate vertices per face and assign face normals
   for (size_t i = 0; i < data.faceIndices.size(); i += 3)
   {
      const unsigned int v0 = data.faceIndices[i];
      const unsigned int v1 = data.faceIndices[i + 1];
      const unsigned int v2 = data.faceIndices[i + 2];

      // Face index (i / 3) → 0 to 5 for the 6 cube faces
      unsigned int faceIdx = i / 6; // 6 indices per face (2 triangles × 3 vertices)
      const Vector3& faceNormal = data.faceNormals[faceIdx];
      // Add vertices with face normals
      for (unsigned int v : {v0, v1, v2})
      {
         const Vector3& currentVertex = data.points[v];
         const auto vertexLine =
            {
               currentVertex.X(), currentVertex.Y(), currentVertex.Z(),  // Position
               faceNormal.X(),    faceNormal.Y(), faceNormal.Z()   // Normal
            };
         verticesNormalsUVs.insert(verticesNormalsUVs.end(), vertexLine);
      }

      // Add indices (sequential, since vertices are duplicated)
      faceIndices.push_back(i);       // v0
      faceIndices.push_back(i + 1);   // v1
      faceIndices.push_back(i + 2);   // v2
   }
   faceCount = faceIndices.size() / 3;
}
