#include "Vector3.h"

#include <math.h>

Vector3::Vector3(const float _x, const float _y, const float _z)
  : x(_x), y(_y), z(_z)
{
}

Vector3& Vector3::operator*=(const float factor)
{
   x *= factor;
   y *= factor;
   z *= factor;
   return *this;
}

Vector3 Vector3::operator+(const Vector3 &other)
{
   return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 *Vector3::CreateMedian(const Vector3 &other) const
{
   return new Vector3((x + other.x) / 2.f, (y + other.y) / 2.f,
                      (z + other.z) / 2.f);
}

float Vector3::X() const
{
   return x;
}

float Vector3::Y() const
{
   return y;
}

float Vector3::Z() const
{
   return z;
}

float Vector3::ComputeLength() const
{
   return sqrt(x*x + y*y + z*z);
}
