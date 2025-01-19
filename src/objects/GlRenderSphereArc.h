#ifndef GLRENDERSPHEREARC_H
#define GLRENDERSPHEREARC_H

#include "GlRenderSphere.h"

#include "SphereTextureMappings.h"

class GlRenderSphereArc : public GlRenderSphere
{
public:
   GlRenderSphereArc(const float angleInRadians, Material* _material);
   virtual ~GlRenderSphereArc() = default;

protected:
   void PopulateGeometry(const unsigned int subdivisions) override;

private:
   void PopulateCoordinates();
   void PopulateTriangles();

   SphereTextureMapping* CreateMappingAlgorithm();

   float arcAngleInRadians;
   unsigned int horizontalPointCount = 0;
   unsigned int verticalPointCount = 0;

};

#endif // GLRENDERSPHEREARC_H
