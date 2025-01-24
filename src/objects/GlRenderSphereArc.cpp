#include "GlRenderSphereArc.h"

#include <cmath>

GlRenderSphereArc::GlRenderSphereArc(const float angleInRadians, Material *_material,
                                     const unsigned int _subdivisions, const TextureMap mappingAlgorithm)
  : GlRenderSphere(_material, _subdivisions, mappingAlgorithm),
  arcAngleInRadians(angleInRadians)
{
}

void GlRenderSphereArc::PopulateGeometry()
{
   horizontalPointCount = pow(2, subdivisions + 2);
   verticalPointCount = pow(2, subdivisions + 1);

   PopulateCoordinates();
   PopulateTriangles();
}

void GlRenderSphereArc::PopulateCoordinates()
{
   const GLfloat radius = 1.f;
   const GLfloat horizontalAnglePerSlice = arcAngleInRadians / static_cast<GLfloat>(horizontalPointCount);
   const GLfloat verticalAnglePerSlice = M_PI / static_cast<GLfloat>(verticalPointCount);

   SphereTextureMapping* textureMappingAlgorithm = CreateMappingAlgorithm();

   points.emplace_back(0.f, radius, 0.f);
   normals.emplace_back(0.f, 1.f, 0.f);

   textureMappingAlgorithm->MapTop();

   for (int i=1; i<verticalPointCount; ++i)
   {
      const GLfloat verticalAngle = i * verticalAnglePerSlice;

      const float y = radius * cos(verticalAngle);
      const float plane = radius * sin(verticalAngle);

      for (int j=0; j<=horizontalPointCount; ++j)
      {
         const GLfloat horizontalAngle = j * horizontalAnglePerSlice;
         const float x = plane * sin(horizontalAngle);
         const float z = plane * -cos(horizontalAngle);

         const Vector3 point(x, y, z);
         points.push_back(point);
         normals.push_back(point.Normalized());

         textureMappingAlgorithm->Map(i, j);
      }
   }

   points.emplace_back(0.f, -radius, 0.f);
   normals.emplace_back(0.f, -1.f, 0.f);
   textureMappingAlgorithm->MapBottom();
}

void GlRenderSphereArc::PopulateTriangles()
{
   for (int j=0; j<horizontalPointCount; ++j)
      triangles.emplace_back(0, j+2, j+1);

   for (int i=0; i<verticalPointCount-2; ++i)
   {
      const unsigned int verticalIndex = i * (horizontalPointCount + 1) + 1;
      for (int j=0; j<=horizontalPointCount; ++j)
      {
         const unsigned int indexP1 = j + verticalIndex;
         const unsigned int indexP2 = indexP1 + 1;
         const unsigned int indexP3 = indexP1 + horizontalPointCount;
         const unsigned int indexP4 = indexP3 + 1;
         triangles.emplace_back(indexP1, indexP2, indexP4);
         triangles.emplace_back(indexP1, indexP4, indexP3);
      }
   }

   const unsigned int finalIndex = points.size()-1;
   const unsigned int startIndex = finalIndex - horizontalPointCount-1;
   for (int i = startIndex; i < finalIndex; ++i)
      triangles.emplace_back(finalIndex, i, i+1);
}

SphereTextureMapping *GlRenderSphereArc::CreateMappingAlgorithm()
{
   if (textureMapping == TextureMap::FullWrap)
      return new FullWrapSphereMapping(textureCoordinates, horizontalPointCount, verticalPointCount);
   else if (textureMapping == TextureMap::HalfWrap)
      return new HalfWrapSphereMapping(textureCoordinates, horizontalPointCount, verticalPointCount);
   return nullptr;
}
