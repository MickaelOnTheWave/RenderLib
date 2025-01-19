#include "GlRenderPlane.h"

using namespace std;

GlRenderPlane::GlRenderPlane(Material *_material)
  : GlRenderObject(_material)
{
   InitializeGlData();
}

void GlRenderPlane::Render()
{
   const unsigned int vertexCount = 6;
   glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
}

std::vector<GLfloat> GlRenderPlane::CreateVertexBufferData() const
{
   const GLfloat textureScale = 4.f;
   const GLfloat value = 0.5f;
   const vector<GLfloat> verticesNormalsTexcoords = {
       -value, -value,  0.f,   0.f,0.f,1.f,   0.f,0.f,
        value, -value,  0.f,   0.f,0.f,1.f,   textureScale,0.f,
        value,  value,  0.f,   0.f,0.f,1.f,   textureScale,textureScale,
       -value,  value,  0.f,   0.f,0.f,1.f,   0.f,textureScale,
   };
   return verticesNormalsTexcoords;
}

std::vector<GLuint> GlRenderPlane::CreateIndexData() const
{
   return {0,1,2, 0,2,3};
}
