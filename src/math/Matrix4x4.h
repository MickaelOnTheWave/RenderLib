#ifndef MATRIX4X4_H
#define MATRIX4X4_H


class Matrix4x4
{
public:
   Matrix4x4();
   Matrix4x4(const float* _data);

   static Matrix4x4 Identity();
   static Matrix4x4 Translation(const float x, const float y, const float z);
   static Matrix4x4 Scale(const float x, const float y, const float z);
   static Matrix4x4 Scale(const float s);
   static Matrix4x4 RotationX(const float angle);
   static Matrix4x4 RotationY(const float angle);

   Matrix4x4& operator=(const float* other);
   Matrix4x4 operator*(const Matrix4x4& other);
   Matrix4x4& operator*=(const Matrix4x4& other);

   float* getData();

private:
   float ComputeLineRowProduct(const float* lineMatrix,
                               const float* rowMatrix,
                               const int i, const int j) const;
   static float* getIdentityData();

   float data[16];
};

#endif // MATRIX4X4_H
