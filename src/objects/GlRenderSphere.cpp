#include "GlRenderSphere.h"

using namespace std;

GlRenderSphere::GlRenderSphere(Material *_material, const unsigned int _subdivisions,
                               const TextureMap mappingAlgorithm)
  : GlRenderObject(_material),
  subdivisions(_subdivisions), textureMapping(mappingAlgorithm)
{
}

void GlRenderSphere::Initialize()
{
   PopulateGeometry();
   InitializeGlData();
}

void GlRenderSphere::Render()
{
   const unsigned int vertexPerFace = 3;
   const unsigned int faceCount = triangles.size();
   const unsigned int indexCount = vertexPerFace * faceCount;
   glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

vector<GLfloat> GlRenderSphere::CreateVertexBufferData() const
{
   vector<float> data;

   for (unsigned int i=0; i < points.size(); ++i)
   {
      const auto& point = points[i];
      const auto& normal = normals[i];
      const auto& texCoord = textureCoordinates[i];

      // Point data
      data.push_back(point.X());
      data.push_back(point.Y());
      data.push_back(point.Z());

      // Normal data
      data.push_back(normal.X());
      data.push_back(normal.Y());
      data.push_back(normal.Z());

      // Texture coord data
      data.push_back(texCoord.u);
      data.push_back(texCoord.v);
   }
   return data;
}

std::vector<GLuint> GlRenderSphere::CreateIndexData() const
{
   vector<GLuint> data;
   for (const auto& triangle : triangles)
   {
      data.push_back(triangle.GetP1());
      data.push_back(triangle.GetP2());
      data.push_back(triangle.GetP3());
   }
   return data;
}
