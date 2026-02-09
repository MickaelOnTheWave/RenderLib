#ifndef GLTRIANGULATEDGEOMETRY_H
#define GLTRIANGULATEDGEOMETRY_H

#include "GlGeometry.h"
#include "scene/resources/geometries/Triangulator.h"

#include <vector>

class GlTriangulatedGeometry : public GlGeometry
{
public:
   GlTriangulatedGeometry(const TriangulatedData& data);

   std::vector<float> verticesNormalsUVs; // TODO : add UVs
   std::vector<unsigned int> faceIndices;

private:
   struct UV {
      float x, y;
   };

   std::vector<float> CreateVertexBufferData() const override;
   std::vector<unsigned int> CreateIndexData() const override;

   void CreateWithFaceNormals(const TriangulatedData& data);
   void AddDataLine(const TriangulatedData& data, const Vector3& normal, const unsigned int vertexIndex, const UV& uv);
};

#endif // GLTRIANGULATEDGEOMETRY_H
