#ifndef GLRENDERSPHERE_H
#define GLRENDERSPHERE_H

#include "GlRenderObject.h"

#include <glad/gl.h>
#include <vector>

#include "math/Triangle.h"
#include "math/Vector3.h"

class GlRenderSphere : public GlRenderObject
{
public:
   enum class TextureMap
   {
      FullWrap,
      HalfWrap,
      HalfPolarProjection
   };

   GlRenderSphere(Material* _material, const unsigned int _subdivisions,
                  const TextureMap mappingAlgorithm);

   void Initialize() override;

   void Render() override;

protected:
   virtual void PopulateGeometry() = 0;

   std::vector<GLfloat> CreateVertexBufferData() const override;
   std::vector<GLuint> CreateIndexData() const override;

   std::vector<Vector3> points;
   std::vector<Vector3> normals;
   std::vector<TexCoord> textureCoordinates;

   std::list<Triangle> triangles;

   const unsigned int subdivisions;
   TextureMap textureMapping = TextureMap::FullWrap;
};

#endif // GLRENDERSPHERE_H
