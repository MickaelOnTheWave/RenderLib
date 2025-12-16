#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <vector>

#include "ImageData.h"
#include "math/Vector3.h"

class TextureManager
{
public:
   TextureManager() = default;

   unsigned int AddTexture(const std::string& file, const int colorChannels);
   unsigned int AddTexture(const ImageData& imageData, const int glFormat = 0);
   unsigned int AddPlainColorTexture(const Vector3& color);

   std::vector<unsigned int> GetTextureObjects() const;

private:
   unsigned int CreateGlTexture(const std::string& file, const int colorChannels);

   unsigned char* CreatePlainColorData(const Vector3& color) const;

   unsigned int LoadTextureData(const int width, const int height,
                                const int textureFormat, const unsigned char* textureData);

   std::vector<unsigned int> textureObjects;
};

#endif // TEXTUREMANAGER_H
