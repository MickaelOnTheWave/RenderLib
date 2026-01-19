#ifndef GLTEXTUREMANAGER_H
#define GLTEXTUREMANAGER_H

#include <vector>

#include "scene/resources/Texture.h"
#include "renderers/opengl/GlTexture.h"

class GlTextureManager
{
public:
   GlTextureManager() = default;

   void Create(const Texture& texture);

private:


   std::vector<GlTexture> textureObjects;
};

#endif // GLTEXTUREMANAGER_H
