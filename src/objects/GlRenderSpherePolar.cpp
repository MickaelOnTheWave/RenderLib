#include "GlRenderSpherePolar.h"

#include <cmath>

GlRenderSpherePolar::GlRenderSpherePolar(Material *_material, const unsigned int _subdivisions,
                                         const TextureMap mappingAlgorithm)
  : GlRenderSphereArc(2 * M_PI, _material, _subdivisions, mappingAlgorithm, 1.f, 1.f)
{
}
