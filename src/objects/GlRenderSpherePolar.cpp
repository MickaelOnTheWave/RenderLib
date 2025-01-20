#include "GlRenderSpherePolar.h"

#include <cmath>

GlRenderSpherePolar::GlRenderSpherePolar(Material *_material)
  : GlRenderSphereArc(2 * M_PI, _material)
{
}
