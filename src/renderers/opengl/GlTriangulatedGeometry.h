#ifndef GLTRIANGULATEDGEOMETRY_H
#define GLTRIANGULATEDGEOMETRY_H

#include "GlGeometry.h"
#include "scene/resources/geometries/Triangulator.h"

#include <vector>

class GlTriangulatedGeometry : public GlGeometry
{
public:
   GlTriangulatedGeometry(const TriangulatedData& data);

   std::vector<float> verticesNormalsUVs;
   std::vector<unsigned int> faceIndices;

private:
   std::vector<float> CreateVertexBufferData() const override;
   std::vector<unsigned int> CreateIndexData() const override;

   void CreateWithFaceNormals(const TriangulatedData& data);
};

#endif // GLTRIANGULATEDGEOMETRY_H
