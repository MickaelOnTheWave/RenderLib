#include <gtest/gtest.h>

#include "math/Matrix4x4.h"

const float errorMargin = 0.0001f;

TEST(MatrixTests, Identity)
{
   const Matrix4x4 identity = Matrix4x4::Identity();

   for (int i=0; i<16; i+=5)
      EXPECT_NEAR(identity[i], 1, errorMargin);
   for (int i=1; i<5; ++i)
      EXPECT_NEAR(identity[i], 0, errorMargin);
   for (int i=6; i<10; ++i)
      EXPECT_NEAR(identity[i], 0, errorMargin);
   for (int i=11; i<15; ++i)
      EXPECT_NEAR(identity[i], 0, errorMargin);
}

TEST(MatrixTests, Translation)
{
   const Matrix4x4 matrix = Matrix4x4::Translation(2.5, 3.6, 4.7);

   for (int i=0; i<16; i+=5)
      EXPECT_NEAR(matrix[i], 1, errorMargin);
   for (int i=1; i<5; ++i)
      EXPECT_NEAR(matrix[i], 0, errorMargin);
   for (int i=6; i<10; ++i)
      EXPECT_NEAR(matrix[i], 0, errorMargin);
   EXPECT_NEAR(matrix[11], 0, errorMargin);

   EXPECT_NEAR(matrix[12], 2.5, errorMargin);
   EXPECT_NEAR(matrix[13], 3.6, errorMargin);
   EXPECT_NEAR(matrix[14], 4.7, errorMargin);
   EXPECT_NEAR(matrix[15], 1, errorMargin);
}

TEST(MatrixTests, Scale)
{
   const Matrix4x4 matrix = Matrix4x4::Scale(1.2, 3.4, 5.6);

   for (int i=1; i<5; ++i)
      EXPECT_NEAR(matrix[i], 0, errorMargin);
   for (int i=6; i<10; ++i)
      EXPECT_NEAR(matrix[i], 0, errorMargin);
   for (int i=11; i<15; ++i)
      EXPECT_NEAR(matrix[i], 0, errorMargin);

   EXPECT_NEAR(matrix[0], 1.2, errorMargin);
   EXPECT_NEAR(matrix[5], 3.4, errorMargin);
   EXPECT_NEAR(matrix[10], 5.6, errorMargin);
   EXPECT_NEAR(matrix[15], 1, errorMargin);
}

TEST(MatrixTests, RotationX)
{
   const Matrix4x4 matrix = Matrix4x4::RotationX(M_PI_2);

   EXPECT_NEAR(matrix[0], 1, errorMargin);
   EXPECT_NEAR(matrix[1], 0, errorMargin);
   EXPECT_NEAR(matrix[2], 0, errorMargin);
   EXPECT_NEAR(matrix[3], 0, errorMargin);

   EXPECT_NEAR(matrix[4], 0, errorMargin);
   EXPECT_NEAR(matrix[5], 0, errorMargin);
   EXPECT_NEAR(matrix[6], -1, errorMargin);
   EXPECT_NEAR(matrix[7], 0, errorMargin);

   EXPECT_NEAR(matrix[8], 0, errorMargin);
   EXPECT_NEAR(matrix[9], 1, errorMargin);
   EXPECT_NEAR(matrix[10], 0, errorMargin);
   EXPECT_NEAR(matrix[11], 0, errorMargin);

   EXPECT_NEAR(matrix[12], 0, errorMargin);
   EXPECT_NEAR(matrix[13], 0, errorMargin);
   EXPECT_NEAR(matrix[14], 0, errorMargin);
   EXPECT_NEAR(matrix[15], 1, errorMargin);
}

TEST(MatrixTests, RotationY)
{
   const Matrix4x4 matrix = Matrix4x4::RotationY(M_PI_2);

   EXPECT_NEAR(matrix[0], 0, errorMargin);
   EXPECT_NEAR(matrix[1], 0, errorMargin);
   EXPECT_NEAR(matrix[2], 1, errorMargin);
   EXPECT_NEAR(matrix[3], 0, errorMargin);

   EXPECT_NEAR(matrix[4], 0, errorMargin);
   EXPECT_NEAR(matrix[5], 1, errorMargin);
   EXPECT_NEAR(matrix[6], 0, errorMargin);
   EXPECT_NEAR(matrix[7], 0, errorMargin);

   EXPECT_NEAR(matrix[8], -1, errorMargin);
   EXPECT_NEAR(matrix[9], 0, errorMargin);
   EXPECT_NEAR(matrix[10], 0, errorMargin);
   EXPECT_NEAR(matrix[11], 0, errorMargin);

   EXPECT_NEAR(matrix[12], 0, errorMargin);
   EXPECT_NEAR(matrix[13], 0, errorMargin);
   EXPECT_NEAR(matrix[14], 0, errorMargin);
   EXPECT_NEAR(matrix[15], 1, errorMargin);
}

TEST(MatrixTests, OperatorEqual)
{
   Matrix4x4 matrix1 = Matrix4x4::Identity();
   const Matrix4x4 matrix2({
      0,  1,  2,  3,
      4,  5,  6,  7,
      8,  9,  10, 11,
      12, 13, 14, 15
   });

   matrix1 = matrix2;

   for (int i=0; i<16; ++i)
      EXPECT_NEAR(matrix1[i], i, errorMargin);
}

TEST(MatrixTests, OperatorMultiply_Identity)
{
   const Matrix4x4 matrix1 = Matrix4x4::Identity();
   const Matrix4x4 matrix2 = Matrix4x4::RotationX(M_PI_2);

   const Matrix4x4 matrix3 = matrix1 * matrix2;
   const bool isEqual = matrix3.Equals(matrix2, errorMargin);
   EXPECT_TRUE(isEqual);
}

TEST(MatrixTests, OperatorMultiply)
{
   const Matrix4x4 matrix1 = Matrix4x4::Translation(1, 2, 3);
   const Matrix4x4 matrix2 = Matrix4x4::RotationX(M_PI_2);

   const Matrix4x4 matrix3 = matrix1 * matrix2;

   EXPECT_NEAR(matrix3[0], 1, errorMargin);
   EXPECT_NEAR(matrix3[1], 0, errorMargin);
   EXPECT_NEAR(matrix3[2], 0, errorMargin);
   EXPECT_NEAR(matrix3[3], 0, errorMargin);

   EXPECT_NEAR(matrix3[4], 0, errorMargin);
   EXPECT_NEAR(matrix3[5], 0, errorMargin);
   EXPECT_NEAR(matrix3[6], -1, errorMargin);
   EXPECT_NEAR(matrix3[7], 0, errorMargin);

   EXPECT_NEAR(matrix3[8], 0, errorMargin);
   EXPECT_NEAR(matrix3[9], 1, errorMargin);
   EXPECT_NEAR(matrix3[10], 0, errorMargin);
   EXPECT_NEAR(matrix3[11], 0, errorMargin);

   EXPECT_NEAR(matrix3[12], 1, errorMargin);
   EXPECT_NEAR(matrix3[13], 3, errorMargin);
   EXPECT_NEAR(matrix3[14], -2, errorMargin);
   EXPECT_NEAR(matrix3[15], 1, errorMargin);
}
