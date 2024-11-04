#ifndef GLRENDERSPHERETETRAHEDRON_H
#define GLRENDERSPHERETETRAHEDRON_H

#include "GlRenderSubdividedSphere.h"

class GlRenderSphereTetrahedron : public GlRenderSubdividedSphere
{
public:
   virtual ~GlRenderSphereTetrahedron() = default;

protected:
   void PopulateInitialGeometry() override;
};

#endif // GLRENDERSPHERETETRAHEDRON_H
