#ifndef VECTOR3_H
#define VECTOR3_H

#include <vector>

class Vector3
{
public:
   explicit Vector3(const float _x=0, const float _y=0, const float _z=0);
   Vector3(const Vector3& other);

   Vector3& operator=(const Vector3& other);
   Vector3& operator*=(const float factor);

   Vector3 operator+(const Vector3& other) const;
   Vector3 operator-(const Vector3& other) const;

   Vector3 operator+(const float factor) const;
   Vector3 operator*(const float factor) const;

   Vector3* CreateMedian(const Vector3& other) const;
   Vector3 CrossProduct(const Vector3& other) const;
   Vector3 Normalized() const;

   float DotProduct(const Vector3& other) const;

   float X() const;
   float Y() const;
   float Z() const;

   std::vector<float> GetData() const;

   float ComputeLength() const;

   void Normalize();

private:
   float x, y, z;
};

#endif // VECTOR3_H
