#ifndef GLMATERIAL_H
#define GLMATERIAL_H

#include "GlTexture.h"

class GlMaterial
{
public:
   GlMaterial();

   unsigned int sceneId;
   const GlTexture* glDiffuseTexture;
   const GlTexture* glSpecularTexture;
   float shininess;
};

#endif // GLMATERIAL_H
