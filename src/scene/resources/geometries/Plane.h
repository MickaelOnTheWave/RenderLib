#ifndef PLANE_H
#define PLANE_H

#include "scene/resources/Geometry.h"

#include "math/Vector3.h"

class Plane : public Geometry
{
public:
   Plane();

private:
   Vector3 point;
   Vector3 normalVector;
};

#endif // PLANE_H
