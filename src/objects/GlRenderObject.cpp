#include "GlRenderObject.h"

#include <glad/gl.h>

using namespace std;

GlRenderObject::GlRenderObject(Material *_material, const std::string& _name)
    : EngineEntity(_name), material(_material)
{
}

void GlRenderObject::PrepareRendering(const unsigned int shaderProgramId)
{
   if (material)
   {
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, material->diffuseTextureId);
      glActiveTexture(GL_TEXTURE1);
      glBindTexture(GL_TEXTURE_2D, material->specularTextureId);
   }

   glBindVertexArray(vertexArrayObject);
}

Material *GlRenderObject::GetMaterial() const
{
   return material;
}

void GlRenderObject::InitializeGlData()
{
   glGenVertexArrays(1, &vertexArrayObject);
   glBindVertexArray(vertexArrayObject);

   setupVertexBufferObject();
   setupElementBufferObject();

   setupVertexArrayAttributes();
}

void GlRenderObject::setupVertexBufferObject()
{
   const vector<float> verticesColorsTexcoords = CreateVertexBufferData();

   glGenBuffers(1, &vertexBufferObject);
   glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
   glBufferData(GL_ARRAY_BUFFER, verticesColorsTexcoords.size() * sizeof(float), verticesColorsTexcoords.data(), GL_STATIC_DRAW);
}

void GlRenderObject::setupElementBufferObject()
{
   const vector<GLuint> indices = CreateIndexData();

   glGenBuffers(1, &elementBufferObject);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void GlRenderObject::setupVertexArrayAttributes()
{
   const GLsizei stride = 8 * sizeof(float);

   // Position
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
   glEnableVertexAttribArray(0);

   // Normal
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
   glEnableVertexAttribArray(1);

   // Texture coordinates
   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));
   glEnableVertexAttribArray(2);
}

