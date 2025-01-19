#ifndef GLRENDERPLANE_H
#define GLRENDERPLANE_H

#include "GlRenderObject.h"

class GlRenderPlane : public GlRenderObject
{
public:
   explicit GlRenderPlane(Material* _material);

   void Render() override;

protected:
   std::vector<GLfloat> CreateVertexBufferData() const override;
   std::vector<GLuint> CreateIndexData() const override;

};

#endif // GLRENDERPLANE_H
