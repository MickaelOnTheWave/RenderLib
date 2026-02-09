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
   std::vector<UV> hardCodedUvs;
   hardCodedUvs.push_back({0.f, 0.f});
   hardCodedUvs.push_back({1.f, 0.f});
   hardCodedUvs.push_back({0.f, 1.f});

   for (const auto& face : data.faces)
   {
      const unsigned int v0 = face.vertexIndices[0];
      const unsigned int v1 = face.vertexIndices[1];
      const unsigned int v2 = face.vertexIndices[2];

      for (unsigned int i=0; i<3; ++i)
         AddDataLine(data, face.normal, face.vertexIndices[i], hardCodedUvs[i]);

      faceIndices.push_back(v0);
      faceIndices.push_back(v1);
      faceIndices.push_back(v2);
   }
   faceCount = data.faces.size();
}

void GlTriangulatedGeometry::AddDataLine(const TriangulatedData& data, const Vector3& normal, const unsigned int vertexIndex, const UV& uv)
{
   const Vector3& currentVertex = data.points[vertexIndex];
   const auto vertexLine =
      {
         currentVertex.X(), currentVertex.Y(), currentVertex.Z(),
         normal.X(),        normal.Y(),        normal.Z(),
         uv.x,              uv.y
      };
   verticesNormalsUVs.insert(verticesNormalsUVs.end(), vertexLine);
}
