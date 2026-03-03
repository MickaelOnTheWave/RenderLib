#include "Matrix4x4.h"

#include <cmath>

Matrix4x4::Matrix4x4()
{
   *this = Identity();
}

Matrix4x4::Matrix4x4(const float* _data)
{
   for (int i=0; i<16; ++i)
      data[i] = _data[i];
}

Matrix4x4::Matrix4x4(const glm::mat4 &matrix)
{
   for (int i=0; i<4; ++i)
   {
      for (int j=0; j<4; ++j)
         data[i*4 + j] = matrix[i][j];
   }
}

Matrix4x4 Matrix4x4::Identity()
{
   const float newData[16] = {
      1.f, 0.f, 0.f, 0.f,
      0.f, 1.f, 0.f, 0.f,
      0.f, 0.f, 1.f, 0.f,
      0.f, 0.f, 0.f, 1.f
   };
   return Matrix4x4(newData);
}

Matrix4x4 Matrix4x4::Translation(const Vector3 &value)
{
   return Translation(value.X(), value.Y(), value.Z());
}

Matrix4x4 Matrix4x4::Translation(const float x, const float y,
                                 const float z)
{
   const float newData[16] = {
      1.f, 0.f, 0.f, 0.f,
      0.f, 1.f, 0.f, 0.f,
      0.f, 0.f, 1.f, 0.f,
      x,     y,   z, 1.f
   };
   return Matrix4x4(newData);
}

Matrix4x4 Matrix4x4::Scale(const float x, const float y, const float z)
{
   const float newData[16] = {
       x,   0.f, 0.f, 0.f,
       0.f,   y, 0.f, 0.f,
       0.f, 0.f,   z, 0.f,
       0.f, 0.f, 0.f, 1.f
   };
   return Matrix4x4(newData);
}

Matrix4x4 Matrix4x4::Scale(const float s)
{
   return Scale(s, s, s);
}

Matrix4x4 Matrix4x4::RotationX(const float angleInRadians)
{
   const float cosAngle = cos(angleInRadians);
   const float sinAngle = sin(angleInRadians);
   const float newData[16] =
   {
      1.f,      0.f,       0.f, 0.f,
      0.f, cosAngle, -sinAngle, 0.f,
      0.f, sinAngle,  cosAngle, 0.f,
      0.f,      0.f,       0.f, 1.f
   };
   return Matrix4x4(newData);
}

Matrix4x4 Matrix4x4::RotationY(const float angleInRadians)
{
   const float cosAngle = cos(angleInRadians);
   const float sinAngle = sin(angleInRadians);
   const float newData[16] =
      {
      cosAngle,  0.f, sinAngle, 0.f,
      0.f,       1.f,      0.f, 0.f,
      -sinAngle, 0.f, cosAngle, 0.f,
      0.f,       0.f,      0.f, 1.f
   };
   return Matrix4x4(newData);
}

Matrix4x4& Matrix4x4::operator=(const float* other)
{
   for (int i=0; i<16; ++i)
      data[i] = other[i];
   return *this;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const
{
   Matrix4x4 result;
   for (int i=0; i<4; ++i)
   {
      for (int j=0; j<4; ++j)
      {
         result.data[j*4 + i] = ComputeLineRowProduct(data, other.data, i, j);
      }
   }
   return result;
}

bool Matrix4x4::Equals(const Matrix4x4& other, const float delta) const
{
   for (int i=0; i<16; ++i)
   {
      if (fabs(data[i] - other.data[i]) > delta)
         return false;
   }
   return true;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4 &other)
{
   *this = *this * other;
   return *this;
}

float &Matrix4x4::operator[](const int index)
{
   return data[index];
}

float Matrix4x4::operator[](const int index) const
{
   return data[index];
}

Vector3 Matrix4x4::operator*(const Vector3& vec) const
{
   const float resultX = vec.X() * data[0] + vec.Y() * data[4] + vec.Z() * data[8]  + data[12];
   const float resultY = vec.X() * data[1] + vec.Y() * data[5] + vec.Z() * data[9]  + data[13];
   const float resultZ = vec.X() * data[2] + vec.Y() * data[6] + vec.Z() * data[10] + data[14];
   return Vector3(resultX, resultY, resultZ);
}

float* Matrix4x4::getData()
{
   return data;
}

const float *Matrix4x4::GetData() const
{
   return data;
}

float Matrix4x4::ComputeLineRowProduct(const float* lineMatrix,
                                       const float* rowMatrix,
                                       const int i, const int j) const
{
   float result = 0.f;
   int lineI = j*4;
   int columnI = i;
   for (int k=0; k<4; ++k)
   {
      result += lineMatrix[lineI] * rowMatrix[columnI];
      lineI += 1;
      columnI += 4;
   }
   return result;
}
