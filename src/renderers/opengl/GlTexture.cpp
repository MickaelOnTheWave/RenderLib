#include "GlTexture.h"

#include <glad/gl.h>

GlTexture::GlTexture(const Texture& sceneTexture)
   : sceneId(sceneTexture.GetId()), glTextureId(0)
{
   glTextureId = BindToOpenGL(sceneTexture.GetData());
}

unsigned int GlTexture::BindToOpenGL(const ImageData& imageData)
{
   const int textureFormat = (imageData.channels == 4) ? GL_RGBA: GL_RGB;

   unsigned int textureId = 0;
   const unsigned int textureIdQuantity = 1;
   glGenTextures(textureIdQuantity, &textureId);
   glBindTexture(GL_TEXTURE_2D, textureId);

   // Textures
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageData.width, imageData.height, 0, textureFormat, GL_UNSIGNED_BYTE, imageData.data);
   glGenerateMipmap(GL_TEXTURE_2D);
   return textureId;
}
