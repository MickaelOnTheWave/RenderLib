#ifndef BOX_H
#define BOX_H

#include "scene/resources/Geometry.h"

#include "math/Vector3.h"

class Box : public Geometry
{
public:
   Box();

   Vector3 GetCenter() const;
   void SetCenter(const Vector3& value);

   Vector3 GetSizes() const;
   void SetSizes(const Vector3& value);

private:
   Vector3 center;
   Vector3 sizes;
};

#endif // BOX_H
