#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "NamedEntity.h"

class GlTexture : public NamedEntity
{
public:
    GlTexture(const unsigned int id, const std::string& _name);

    unsigned int textureId;
};

#endif // GLTEXTURE_H
