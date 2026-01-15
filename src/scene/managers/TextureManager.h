#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "ResourceManager.h"

#include "scene/resources/Texture.h"

class TextureManager : public ResourceManager<Texture>
{
public:
   TextureManager() = default;
   virtual ~TextureManager() = default;
};

#endif // TEXTUREMANAGER_H
