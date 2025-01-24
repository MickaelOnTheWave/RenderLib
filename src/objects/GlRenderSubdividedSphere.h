#ifndef GLRENDERSUBDIVIDEDSPHERE_H
#define GLRENDERSUBDIVIDEDSPHERE_H

#include "GlRenderSphere.h"

class GlRenderSubdividedSphere : public GlRenderSphere
{
public:
   GlRenderSubdividedSphere(Material* _material, const unsigned int _subdivisions,
                            const TextureMap mappingAlgorithm);

protected:
   void PopulateGeometry() override;

   virtual void PopulateInitialGeometry() = 0;
   void CreateSubdividedSphere(const unsigned int subdivisions);
};

#endif // GLRENDERSUBDIVIDEDSPHERE_H
