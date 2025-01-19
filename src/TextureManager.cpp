#include "TextureManager.h"

#include <glad/gl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int TextureManager::AddTexture(const std::string &file, const int format)
{
   const int textureId = CreateGlTexture(Texture(file, format));
   textureObjects.push_back(textureId);
   return textureId;
}

unsigned int TextureManager::CreateGlTexture(const Texture &texture)
{
   unsigned int textureIndex = 0;

   int width, height, nrChannels;
   unsigned char *textureData = stbi_load(texture.file.c_str(), &width, &height, &nrChannels, 0);
   if (textureData)
   {
      const unsigned int textureIdQuantity = 1;
      glGenTextures(textureIdQuantity, &textureIndex);

      textureObjects.push_back(textureIndex);

      glBindTexture(GL_TEXTURE_2D, textureIndex);

      // Textures
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, texture.format, GL_UNSIGNED_BYTE, textureData);
      glGenerateMipmap(GL_TEXTURE_2D);

      stbi_image_free(textureData);
   }

   return textureIndex;
}
