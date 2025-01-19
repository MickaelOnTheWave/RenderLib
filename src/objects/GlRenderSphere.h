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
   GlRenderSphere(Material* _material);

   void Initialize(const unsigned int subdivisions);

   void Render() override;

protected:
   virtual void PopulateGeometry(const unsigned int subdivisions) = 0;

   std::vector<GLfloat> CreateVertexBufferData() const override;
   std::vector<GLuint> CreateIndexData() const override;

   std::vector<Vector3> points;
   std::vector<Vector3> normals;
   std::vector<TexCoord> textureCoordinates;

   std::list<Triangle> triangles;
};

#endif // GLRENDERSPHERE_H
