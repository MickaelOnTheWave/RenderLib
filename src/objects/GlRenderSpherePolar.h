#ifndef GLRENDERSPHEREPOLAR_H
#define GLRENDERSPHEREPOLAR_H

#include "GlRenderSphere.h"

#include "SphereTextureMappings.h"

class GlRenderSpherePolar : public GlRenderSphere
{
public:
   GlRenderSpherePolar(Material* _material);
   virtual ~GlRenderSpherePolar() = default;

protected:
   void PopulateGeometry(const unsigned int subdivisions) override;

private:
   void PopulateCoordinates();
   void PopulateTriangles();

   SphereTextureMapping* CreateMappingAlgorithm();

   unsigned int horizontalPointCount = 0;
   unsigned int verticalPointCount = 0;
};

#endif // GLRENDERSPHEREPOLAR_H
