#include "GlTexture.h"

GlTexture::GlTexture(const unsigned int id, const std::string& _name)
    : EngineEntity(_name), textureId(id)
{
}

GlTexture::GlTexture(const GlTexture& other)
   : EngineEntity(other), textureId(other.textureId)
{
}

GlTexture& GlTexture::operator=(const GlTexture& other)
{
   EngineEntity::operator=(other);
   textureId = other.textureId;
   return *this;
}
