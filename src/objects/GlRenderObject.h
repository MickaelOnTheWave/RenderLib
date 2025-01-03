#ifndef GLRENDEROBJECT_H
#define GLRENDEROBJECT_H

#include <vector>
#include <glad/gl.h>

#include "Material.h"

class GlRenderObject
{
public:
   using TextureVec = std::vector<Texture>;

   explicit GlRenderObject(Material* _material);
   virtual ~GlRenderObject() = default;

   virtual void PrepareRendering(const unsigned int shaderProgramId);

   virtual void Render() = 0;

   Material* GetMaterial() const;

   void SetTextures(const TextureVec& textures);

protected:

   virtual std::vector<GLfloat> CreateVertexBufferData() const = 0;
   virtual std::vector<GLuint> CreateIndexData() const = 0;

   void InitializeGlData();

   void setupVertexBufferObject();
   void setupElementBufferObject();
   void setupTextureObject();
   void setupVertexArrayAttributes();

   void generateTextureObject(const char* imagePath, const unsigned int textureIndex,
                              const unsigned int dataFormat);


   unsigned int vertexArrayObject;
   unsigned int vertexBufferObject;
   unsigned int elementBufferObject;
   unsigned int textureObjects[2];
   TextureVec textureFiles;
   Material* material;
};

#endif // GLRENDEROBJECT_H
