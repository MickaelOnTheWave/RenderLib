#include "Vector3.h"

#include <math.h>

Vector3::Vector3(const float _x, const float _y, const float _z)
  : x(_x), y(_y), z(_z)
{
}

Vector3::Vector3(const Vector3& other)
   : x(other.x), y(other.y), z(other.z)
{
}

Vector3& Vector3::operator=(const Vector3& other)
{
   x = other.x;
   y = other.y;
   z = other.z;
   return *this;
}

Vector3& Vector3::operator*=(const float factor)
{
   x *= factor;
   y *= factor;
   z *= factor;
   return *this;
}

Vector3 Vector3::operator+(const Vector3 &other) const
{
   return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3 &other) const
{
   return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator+(const float factor) const
{
   return Vector3(x + factor, y + factor, z + factor);
}

Vector3 Vector3::operator*(const float factor) const
{
   return Vector3(x * factor, y * factor, z * factor);
}

Vector3 Vector3::operator/(const float factor) const
{
   return Vector3(x / factor, y / factor, z / factor);
}

Vector3 *Vector3::CreateMedian(const Vector3 &other) const
{
   return new Vector3((x + other.x) / 2.f, (y + other.y) / 2.f,
                      (z + other.z) / 2.f);
}

Vector3 Vector3::CrossProduct(const Vector3 &other) const
{
   const float resultX = y * other.z - z * other.y;
   const float resultY = z * other.x - x * other.z;
   const float resultZ = x * other.y - y * other.x;
   return Vector3(resultX, resultY, resultZ);
}

Vector3 Vector3::Normalized() const
{
   Vector3 copy(*this);
   copy.Normalize();
   return copy;
}

float Vector3::DotProduct(const Vector3 &other) const
{
   return x * other.x + y * other.y + z * other.z;
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

std::vector<float> Vector3::GetData() const
{
   return std::vector<float>{x, y, z};
}

float Vector3::ComputeLength() const
{
   return sqrt(x*x + y*y + z*z);
}

void Vector3::Normalize()
{
   const float length = ComputeLength();
   x /= length;
   y /= length;
   z /= length;
}
