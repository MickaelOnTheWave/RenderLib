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
   for (const auto& face : data.faces)
   {
      const unsigned int v0 = face.vertexIndices[0];
      const unsigned int v1 = face.vertexIndices[1];
      const unsigned int v2 = face.vertexIndices[2];

      for (unsigned int v : {v0, v1, v2})
      {
         const Vector3& currentVertex = data.points[v];
         const auto vertexLine =
         {
            currentVertex.X(), currentVertex.Y(), currentVertex.Z(),  // Position
            face.normal.X(),   face.normal.Y(),   face.normal.Z()     // Normal
         };
         verticesNormalsUVs.insert(verticesNormalsUVs.end(), vertexLine);
      }

      faceIndices.push_back(v0);
      faceIndices.push_back(v1);
      faceIndices.push_back(v2);
   }
   faceCount = data.faces.size();
}
