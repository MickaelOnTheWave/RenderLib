#ifndef BOX_H
#define BOX_H

#include "scene/resources/Geometry.h"

#include "math/Vector3.h"

class Box : public Geometry
{
public:
   Box();

private:
   Vector3 center;
   Vector3 sizes;
};

#endif // BOX_H
