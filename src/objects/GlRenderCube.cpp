#include "GlRenderCube.h"

#include <glad/gl.h>

using namespace std;

GlRenderCube::GlRenderCube(Material *_material)
  : GlRenderObject(_material)
{
   InitializeGlData();
}

void GlRenderCube::Render()
{
   const unsigned int vertexPerFace = 6;
   const unsigned int facesInCube = 6;
   const unsigned int indexCount = vertexPerFace * facesInCube;
   glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

vector<GLfloat> GlRenderCube::CreateVertexBufferData() const
{
   const GLfloat value = 0.5f;
   const vector<GLfloat> verticesNormalsTexcoords = {
       -value, -value,  value,   0.f,0.f,1.f,   0.f,0.f,
       value, -value,  value,   0.f,0.f,1.f,   1.f,0.f,
       value,  value,  value,   0.f,0.f,1.f,   1.f,1.f,
       -value,  value,  value,   0.f,0.f,1.f,   0.f,1.f,

       value, -value,  value,   1.f,0.f,0.f,   0.f,0.f,
       value, -value,  -value,   1.f,0.f,0.f,   1.f,0.f,
       value, value,  -value,   1.f,0.f,0.f,   1.f,1.f,
       value, value,  value,   1.f,0.f,0.f,   0.f,1.f,

       value, -value, -value,   0.f,0.f,-1.f,   0.f,0.f,
       -value, -value, -value,  0.f,0.f,-1.f,   1.f,0.f,
       -value,  value, -value,   0.f,0.f,-1.f,  1.f,1.f,
       value,  value, -value,   0.f,0.f,-1.f,   0.f,1.f,

       -value, -value, -value,   -1.f,0.f,0.f,   0.f,0.f,
       -value, -value,  value,   -1.f,0.f,0.f,   1.f,0.f,
       -value,  value,  value,   -1.f,0.f,0.f,   1.f,1.f,
       -value,  value, -value,   -1.f,0.f,0.f,   0.f,1.f,

       -value, -value, -value,   0.f,-1.f,0.f,   0.f,0.f,
        value, -value, -value,   0.f,-1.f,0.f,   1.f,0.f,
        value, -value,  value,   0.f,-1.f,0.f,   1.f,1.f,
       -value, -value,  value,   0.f,-1.f,0.f,   0.f,1.f,

       -value,  value, -value,   0.f,1.f,0.f,   0.f,0.f,
        value,  value, -value,   0.f,1.f,0.f,   1.f,0.f,
        value,  value,  value,   0.f,1.f,0.f,   1.f,1.f,
       -value,  value,  value,   0.f,1.f,0.f,   0.f,1.f

   };
   return verticesNormalsTexcoords;
}

vector<GLuint> GlRenderCube::CreateIndexData() const
{
   const vector<GLuint> indices = {
       0,1,2, 0,2,3,
       4,5,6, 4,6,7,
       8,9,10, 8,10,11,
       12,13,14, 12,14,15,
       16,17,18, 16,18,19,
       20,21,22, 20,22,23
   };
   return indices;
}
