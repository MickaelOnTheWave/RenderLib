#ifndef GLTEXTUREMANAGER_H
#define GLTEXTUREMANAGER_H

#include <string>
#include <vector>

#include "GlTexture.h"
#include "ImageData.h"
#include "math/Vector3.h"

class GlTextureManager
{
public:
   GlTextureManager() = default;

   unsigned int AddTexture(const std::string& file, const int colorChannels, const std::string& _name);
   unsigned int AddTexture(const ImageData& imageData, const std::string& _name, const int glFormat = 0);
   unsigned int AddPlainColorTexture(const Vector3& color, const std::string& _name);

   std::vector<GlTexture> GetTextureObjects() const;

private:
   unsigned int CreateGlTexture(const std::string& file, const int colorChannels);

   unsigned char* CreatePlainColorData(const Vector3& color) const;

   unsigned int LoadTextureData(const int width, const int height,
                                const int textureFormat, const unsigned char* textureData);

   std::vector<GlTexture> textureObjects;
};

#endif // GLTEXTUREMANAGER_H
