#include "Box.h"

Box::Box() : Geometry("Box")
{
}

Vector3 Box::GetCenter() const
{
   return center;
}

void Box::SetCenter(const Vector3& value)
{
   center = value;
}

Vector3 Box::GetSizes() const
{
   return sizes;
}

void Box::SetSizes(const Vector3& value)
{
   sizes = value;
}
