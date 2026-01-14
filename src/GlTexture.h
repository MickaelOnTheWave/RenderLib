#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "EngineEntity.h"

class GlTexture : public EngineEntity
{
public:
   GlTexture(const unsigned int id, const std::string& _name);
   GlTexture(const GlTexture& other);

   GlTexture& operator=(const GlTexture& other);

   unsigned int textureId;
};

#endif // GLTEXTURE_H
