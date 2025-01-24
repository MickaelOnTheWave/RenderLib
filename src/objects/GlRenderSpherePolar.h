#ifndef GLRENDERSPHEREPOLAR_H
#define GLRENDERSPHEREPOLAR_H

#include "GlRenderSphereArc.h"

class GlRenderSpherePolar : public GlRenderSphereArc
{
public:
   GlRenderSpherePolar(Material* _material, const unsigned int _subdivisions,
                     const TextureMap mappingAlgorithm);
   virtual ~GlRenderSpherePolar() = default;
};

#endif // GLRENDERSPHEREPOLAR_H
