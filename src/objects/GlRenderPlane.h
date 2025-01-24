#ifndef GLRENDERPLANE_H
#define GLRENDERPLANE_H

#include "GlRenderObject.h"

class GlRenderPlane : public GlRenderObject
{
public:
   explicit GlRenderPlane(Material* _material, const float _textureScale = 1.f);

   void Initialize() override;

   void Render() override;

protected:
   std::vector<GLfloat> CreateVertexBufferData() const override;
   std::vector<GLuint> CreateIndexData() const override;

private:
   const float textureScale;

};

#endif // GLRENDERPLANE_H
