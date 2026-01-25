#include "GlModel.h"

#include <glad/gl.h>

GlModel::GlModel() {}

void GlModelPart::PrepareRendering() const
{
   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, glMaterial->glDiffuseTexture->glTextureId);
   glActiveTexture(GL_TEXTURE1);
   glBindTexture(GL_TEXTURE_2D, glMaterial->glSpecularTexture->glTextureId);

   glBindVertexArray(glGeometry->vertexArrayObject);
}

void GlModelPart::Render() const
{
   const unsigned int vertexPerFace = 3;
   const unsigned int indexCount = vertexPerFace * glGeometry->faceCount;
   glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}
