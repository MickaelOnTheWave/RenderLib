#include "Box.h"

Box::Box() : Geometry("Box")
{
}

Vector3 Box::GetCenter() const
{
   return center;
}

Vector3 Box::GetSizes() const
{
   return sizes;
}
