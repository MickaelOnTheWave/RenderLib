#ifndef GLRENDERSUBDIVIDEDSPHERE_H
#define GLRENDERSUBDIVIDEDSPHERE_H

#include "GlRenderSphere.h"

class GlRenderSubdividedSphere : public GlRenderSphere
{
public:
   GlRenderSubdividedSphere() = default;

protected:
   void PopulateGeometry(const unsigned int subdivisions) override;

   virtual void PopulateInitialGeometry() = 0;
   void CreateSubdividedSphere(const unsigned int subdivisions);
};

#endif // GLRENDERSUBDIVIDEDSPHERE_H
