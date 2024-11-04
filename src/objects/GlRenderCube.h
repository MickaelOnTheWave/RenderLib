#ifndef GLRENDERCUBE_H
#define GLRENDERCUBE_H

#include "GlRenderObject.h"

class GlRenderCube : public GlRenderObject
{
public:
   GlRenderCube(const TextureVec& _textureFiles);

   void Render() override;

protected:
   std::vector<GLfloat> CreateVertexBufferData() const override;
   std::vector<GLuint> CreateIndexData() const override;

   void setupVertexBufferObject();
   void setupElementBufferObject();
};

#endif // GLRENDERCUBE_H
