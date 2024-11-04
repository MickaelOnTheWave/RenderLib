#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
   Vector3(const float _x=0, const float _y=0, const float _z=0);

   Vector3& operator*=(const float factor);

   Vector3 operator+(const Vector3& other);

   Vector3* CreateMedian(const Vector3& other) const;

   float X() const;
   float Y() const;
   float Z() const;

   float* GetData();

   float ComputeLength() const;

private:
   float x, y, z;
};

#endif // VECTOR3_H
