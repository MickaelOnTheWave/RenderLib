#ifndef GLRENDERSPHEREOCTAHEDRON_H
#define GLRENDERSPHEREOCTAHEDRON_H

#include "GlRenderSubdividedSphere.h"

class GlRenderSphereOctahedron : public GlRenderSubdividedSphere
{
public:
   virtual ~GlRenderSphereOctahedron() = default;

protected:
   void PopulateInitialGeometry() override;
};

#endif // GLRENDERSPHEREOCTAHEDRON_H
