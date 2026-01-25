#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "ReferenceResourceManager.h"

#include "scene/resources/Texture.h"

class TextureManager : public ReferenceResourceManager<Texture>
{
public:
   TextureManager() = default;
   virtual ~TextureManager() = default;
};

#endif // TEXTUREMANAGER_H
