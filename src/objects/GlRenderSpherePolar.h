#ifndef GLRENDERSPHEREPOLAR_H
#define GLRENDERSPHEREPOLAR_H

#include "GlRenderSphereArc.h"

class GlRenderSpherePolar : public GlRenderSphereArc
{
public:
   GlRenderSpherePolar(Material* _material);
   virtual ~GlRenderSpherePolar() = default;
};

#endif // GLRENDERSPHEREPOLAR_H
