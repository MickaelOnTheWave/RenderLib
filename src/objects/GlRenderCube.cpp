#include "GlRenderCube.h"

#include <glad/gl.h>

using namespace std;

GlRenderCube::GlRenderCube(const TextureVec &_textureFiles)
{
   SetTextures(_textureFiles);
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
   const vector<GLfloat> verticesColorsTexcoords = {
       -value, -value,  value,   1.f,0.f,0.f,   0.f,0.f,
       value, -value,  value,   0.f,1.f,0.f,   1.f,0.f,
       value,  value,  value,   0.f,0.f,1.f,   1.f,1.f,
       -value,  value,  value,   1.f,1.f,1.f,   1.f,0.f,

       -value, -value, -value,   0.f,0.f,0.f,   1.f,0.f,
       value, -value, -value,   1.f,1.f,0.f,   0.f,0.f,
       value,  value, -value,   0.f,1.f,1.f,   0.f,1.f,
       -value,  value, -value,   1.f,0.f,1.f,   1.f,1.f
   };
   return verticesColorsTexcoords;
}

vector<GLuint> GlRenderCube::CreateIndexData() const
{
   const vector<GLuint> indices = {
       0,1,2, 0,2,3,
       1,5,6, 1,6,2,
       5,4,7, 5,7,6,
       4,0,3, 4,3,7,
       3,2,6, 3,6,7,
       4,5,1, 4,1,0
   };
   return indices;
}
