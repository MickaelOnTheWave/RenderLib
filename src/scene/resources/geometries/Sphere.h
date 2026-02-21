#ifndef SPHERE_H
#define SPHERE_H

#include "scene/resources/Geometry.h"

#include "math/Vector3.h"

class Sphere : public Geometry
{
public:
   Sphere();

private:
   Vector3 center;
   float radius;
};

#endif // SPHERE_H
