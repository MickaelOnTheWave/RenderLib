#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <vector>

#include "Material.h"

class TextureManager
{
public:
   TextureManager() = default;

   unsigned int AddTexture(const std::string& file, const int format);

private:
   unsigned int CreateGlTexture(const Texture& texture);

   std::vector<unsigned int> textureObjects;
};

#endif // TEXTUREMANAGER_H
