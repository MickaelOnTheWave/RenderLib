#ifndef SPHERE_H
#define SPHERE_H

#include "scene/resources/Geometry.h"

#include <vector>
#include "math/Vector3.h"

class Sphere : public Geometry
{
public:
   Sphere();

private:
   std::vector<Vector3> center;
   float radius;
};

#endif // SPHERE_H
