#ifndef GLRENDEROBJECT_H
#define GLRENDEROBJECT_H

#include <vector>
#include <glad/gl.h>

#include "Material.h"

class GlRenderObject
{
public:
   explicit GlRenderObject(Material* _material);
   virtual ~GlRenderObject() = default;

   virtual void PrepareRendering(const unsigned int shaderProgramId);

   virtual void Initialize() = 0;

   virtual void Render() = 0;

   Material* GetMaterial() const;

protected:

   virtual std::vector<GLfloat> CreateVertexBufferData() const = 0;
   virtual std::vector<GLuint> CreateIndexData() const = 0;

   void InitializeGlData();

   void setupVertexBufferObject();
   void setupElementBufferObject();
   void setupVertexArrayAttributes();

   unsigned int vertexArrayObject;
   unsigned int vertexBufferObject;
   unsigned int elementBufferObject;
   Material* material;
};

#endif // GLRENDEROBJECT_H
