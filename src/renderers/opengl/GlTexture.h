#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "scene/resources/Texture.h"

class GlTexture
{
public:
   GlTexture(const Texture& sceneTexture);

private:
   unsigned int BindToOpenGL(const ImageData& imageData);

   unsigned int sceneId;
   unsigned int glTextureId;
};

#endif // GLTEXTURE_H
