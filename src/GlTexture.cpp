#include "GlTexture.h"

GlTexture::GlTexture(const unsigned int id, const std::string& _name)
    : NamedEntity(_name), textureId(id)
{
}
