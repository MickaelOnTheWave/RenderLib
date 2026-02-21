#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "scene/resources/Geometry.h"
#include "math/Vector3.h"


class Triangle : public Geometry
{
public:
   Triangle();

   Vector3 point1;
   Vector3 point2;
   Vector3 point3;
};

#endif // TRIANGLE_H
