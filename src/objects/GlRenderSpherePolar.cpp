#include "GlRenderSpherePolar.h"

#include <cmath>
#ifndef M_PI
#define M_PI 3.141592
#endif


GlRenderSpherePolar::GlRenderSpherePolar(Material *_material, const unsigned int _subdivisions,
                                         const TextureMap mappingAlgorithm)
  : GlRenderSphereArc(2 * M_PI, _material, _subdivisions, mappingAlgorithm, 1.f, 1.f)
{
}
