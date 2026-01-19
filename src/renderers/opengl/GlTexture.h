#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "scene/resources/Texture.h"

class GlTexture
{
public:
   GlTexture(const Texture& sceneTexture);

   unsigned int sceneId;
   unsigned int glTextureId;
private:
   unsigned int BindToOpenGL(const ImageData& imageData);
};

#endif // GLTEXTURE_H
