#ifndef GLRENDERSPHEREARC_H
#define GLRENDERSPHEREARC_H

#include "GlRenderSphere.h"

#include "SphereTextureMappings.h"

class GlRenderSphereArc : public GlRenderSphere
{
public:
   GlRenderSphereArc(const float angleInRadians, Material* _material,
                     const unsigned int _subdivisions, const TextureMap mappingAlgorithm,
                     const float _textureScaleU, const float _textureScaleV);
   virtual ~GlRenderSphereArc() = default;

protected:
   void PopulateGeometry() override;

private:
   void PopulateCoordinates();
   void PopulateTriangles();

   SphereTextureMapping* CreateMappingAlgorithm();

   float arcAngleInRadians;
   unsigned int horizontalPointCount = 0;
   unsigned int verticalPointCount = 0;
   const float textureScaleU;
   const float textureScaleV;
};

#endif // GLRENDERSPHEREARC_H
