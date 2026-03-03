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

TEST(MatrixTests, OperatorMultiply_TranslationRotation)
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

TEST(MatrixTests, OperatorMultiply_Generic)
{
   const Matrix4x4 matrix1({
      02, 03, 04, 05,
      06, 07, 8., 9.,
      10, 11, 12, 13,
      14, 15, 16, 17
   });
   const Matrix4x4 matrix2({
      18, 19, 20, 21,
      22, 23, 24, 25,
      26, 27, 28, 29,
      30, 31, 32, 33
   });

   const Matrix4x4 matrix3 = matrix1 * matrix2;

   EXPECT_NEAR(matrix3[0], 2*18 + 3*22 + 4*26 + 5*30, errorMargin);
   EXPECT_NEAR(matrix3[1], 2*19 + 3*23 + 4*27 + 5*31, errorMargin);
   EXPECT_NEAR(matrix3[2], 2*20 + 3*24 + 4*28 + 5*32, errorMargin);
   EXPECT_NEAR(matrix3[3], 2*21 + 3*25 + 4*29 + 5*33, errorMargin);

   EXPECT_NEAR(matrix3[4], 6*18 + 7*22 + 8*26 + 9*30, errorMargin);
   EXPECT_NEAR(matrix3[5], 6*19 + 7*23 + 8*27 + 9*31, errorMargin);
   EXPECT_NEAR(matrix3[6], 6*20 + 7*24 + 8*28 + 9*32, errorMargin);
   EXPECT_NEAR(matrix3[7], 6*21 + 7*25 + 8*29 + 9*33, errorMargin);

   EXPECT_NEAR(matrix3[8], 10*18 + 11*22 + 12*26 + 13*30, errorMargin);
   EXPECT_NEAR(matrix3[9], 10*19 + 11*23 + 12*27 + 13*31, errorMargin);
   EXPECT_NEAR(matrix3[10], 10*20 + 11*24 + 12*28 + 13*32, errorMargin);
   EXPECT_NEAR(matrix3[11], 10*21 + 11*25 + 12*29 + 13*33, errorMargin);

   EXPECT_NEAR(matrix3[12], 14*18 + 15*22 + 16*26 + 17*30, errorMargin);
   EXPECT_NEAR(matrix3[13], 14*19 + 15*23 + 16*27 + 17*31, errorMargin);
   EXPECT_NEAR(matrix3[14], 14*20 + 15*24 + 16*28 + 17*32, errorMargin);
   EXPECT_NEAR(matrix3[15], 14*21 + 15*25 + 16*29 + 17*33, errorMargin);
}

TEST(MatrixTests, OperatorMultiply_Vector_Translation)
{
   const Vector3 startingPos(1,0,0);
   const Matrix4x4 matrix1 = Matrix4x4::Translation(0, 1, 0);

   const Vector3 endingPos = matrix1 * startingPos;

   const bool isEqual = endingPos.Equals(Vector3(1,1,0), errorMargin);
   EXPECT_TRUE(isEqual);
}

TEST(MatrixTests, OperatorMultiply_Vector_TranslationRotation)
{
   const Vector3 startingPos(1,0,0);
   const Matrix4x4 matrix1 = Matrix4x4::Translation(1, 0, 0);
   const Matrix4x4 matrix2 = Matrix4x4::RotationY(M_PI_2);

   const Vector3 endingPos1 = matrix1 * matrix2 * startingPos;
   const Vector3 endingPos2 = matrix2 * matrix1 * startingPos;

   bool isEqual = endingPos1.Equals(Vector3(0,0,2), errorMargin);
   EXPECT_TRUE(isEqual);
   isEqual = endingPos2.Equals(Vector3(1,0,1), errorMargin);
   EXPECT_TRUE(isEqual);
}
