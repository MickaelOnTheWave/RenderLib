#ifndef GLRENDERSPHEREPOLAR_H
#define GLRENDERSPHEREPOLAR_H

#include "GlRenderSphere.h"

#include "SphereTextureMappings.h"

class GlRenderSpherePolar : public GlRenderSphere
{
public:
   enum class TextureMap
   {
      FullWrap,
      HalfWrap,
      HalfProjection
   };

   GlRenderSpherePolar() = default;
   virtual ~GlRenderSpherePolar() = default;

   void SetTextureProjection(const TextureMap mapping);

protected:
   void PopulateGeometry(const unsigned int subdivisions) override;

private:
   void PopulateCoordinates();
   void PopulateTriangles();

   SphereTextureMapping* CreateMappingAlgorithm();

   unsigned int horizontalPointCount = 0;
   unsigned int verticalPointCount = 0;
   TextureMap textureMapping = TextureMap::FullWrap;
};

#endif // GLRENDERSPHEREPOLAR_H
