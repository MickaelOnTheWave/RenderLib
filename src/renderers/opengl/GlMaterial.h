#ifndef GLMATERIAL_H
#define GLMATERIAL_H

class GlMaterial
{
public:
   GlMaterial();

   unsigned int sceneId;
   unsigned int glDiffuseTextureId;
   unsigned int glSpecularTextureId;
};

#endif // GLMATERIAL_H
