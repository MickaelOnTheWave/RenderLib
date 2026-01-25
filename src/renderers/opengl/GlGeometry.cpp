#include "GlGeometry.h"

#include <glad/gl.h>
#include <vector>

using namespace std;

GlGeometry::GlGeometry() {}


void GlGeometry::setupVertexBufferObject()
{
   const vector<float> verticesColorsTexcoords = CreateVertexBufferData();

   glGenBuffers(1, &vertexBufferObject);
   glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
   glBufferData(GL_ARRAY_BUFFER, verticesColorsTexcoords.size() * sizeof(float), verticesColorsTexcoords.data(), GL_STATIC_DRAW);
}

void GlGeometry::setupElementBufferObject()
{
   const vector<GLuint> indices = CreateIndexData();

   glGenBuffers(1, &elementBufferObject);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}
