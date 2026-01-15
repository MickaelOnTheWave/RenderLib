#ifndef CYLINDER_H
#define CYLINDER_H

#include "scene/resources/Geometry.h"

#include "math/Vector3.h"

class Cylinder : public Geometry
{
public:
   Cylinder();

private:
   Vector3 center;
   float height;
   float radius;
};

#endif // CYLINDER_H
