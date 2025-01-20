#include "TextureManager.h"

#include <glad/gl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int TextureManager::AddTexture(const std::string &file, const int format)
{
   const unsigned int textureId = CreateGlTexture(Texture(file, format));
   textureObjects.push_back(textureId);
   return textureId;
}

unsigned int TextureManager::AddPlainColorTexture(const Vector3 &color)
{
   unsigned int textureId = 0;

   const int width = 2, height = 2, channels = 3;
   unsigned char *textureData = CreatePlainColorData(color);
   if (textureData)
   {
      textureId = LoadTextureData(width, height, GL_RGB, textureData);
      delete[] textureData;
   }

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
      textureIndex = LoadTextureData(width, height, texture.format, textureData);
      stbi_image_free(textureData);
   }

   return textureIndex;
}

unsigned char *TextureManager::CreatePlainColorData(const Vector3 &color) const
{
   const int width = 2, height = 2, channels = 3;
   auto textureData = new unsigned char[width * height * channels];
   for (unsigned int i=0; i<width * height; ++i)
   {
      const unsigned int pixelIndex = i * channels;
      textureData[pixelIndex] = color.X();
      textureData[pixelIndex+1] = color.Y();
      textureData[pixelIndex+2] = color.Z();
   }

   return textureData;
}

unsigned int TextureManager::LoadTextureData(const int width, const int height, const int textureFormat, const unsigned char *textureData)
{
   unsigned int textureIndex = 0;
   const unsigned int textureIdQuantity = 1;
   glGenTextures(textureIdQuantity, &textureIndex);

   textureObjects.push_back(textureIndex);

   glBindTexture(GL_TEXTURE_2D, textureIndex);

   // Textures
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, textureFormat, GL_UNSIGNED_BYTE, textureData);
   glGenerateMipmap(GL_TEXTURE_2D);

   return textureIndex;
}
