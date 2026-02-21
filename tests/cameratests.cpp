#include <gtest/gtest.h>

#include "math/Angle.h"
#include "scene/resources/Camera.h"

const float errorMargin = 0.0001f;

TEST(CameraTests, LookAt_Identity)
{
   Camera camera("TestCam");
   const Vector3 origin(0, 0, 0);
   const Vector3 yAxis(0, 1, 0);

   camera.LookAt(origin, Vector3(0,0,-1), yAxis);
   const auto camMatrix = camera.GetViewProjectionMatrix();
   const bool isIdentity = camMatrix.Equals(Matrix4x4::Identity(), errorMargin);
   EXPECT_TRUE(isIdentity);
}

TEST(CameraTests, LookAt_OpenGlStart)
{
   Camera camera("TestCam");
   const Vector3 origin(0, 0, 0);
   const Vector3 yAxis(0, 1, 0);

   camera.LookAt(Vector3(0,0,1), origin, yAxis);
   const auto camMatrix = camera.GetViewProjectionMatrix();

   EXPECT_NEAR(camMatrix[0], 1, errorMargin);
   EXPECT_NEAR(camMatrix[1], 0, errorMargin);
   EXPECT_NEAR(camMatrix[2], 0, errorMargin);
   EXPECT_NEAR(camMatrix[3], 0, errorMargin);

   EXPECT_NEAR(camMatrix[4], 0, errorMargin);
   EXPECT_NEAR(camMatrix[5], 1, errorMargin);
   EXPECT_NEAR(camMatrix[6], 0, errorMargin);
   EXPECT_NEAR(camMatrix[7], 0, errorMargin);

   EXPECT_NEAR(camMatrix[8], 0, errorMargin);
   EXPECT_NEAR(camMatrix[9], 0, errorMargin);
   EXPECT_NEAR(camMatrix[10], 1, errorMargin);
   EXPECT_NEAR(camMatrix[11], 0, errorMargin);

   EXPECT_NEAR(camMatrix[12], 0, errorMargin);
   EXPECT_NEAR(camMatrix[13], 0, errorMargin);
   EXPECT_NEAR(camMatrix[14], -1, errorMargin);
   EXPECT_NEAR(camMatrix[15], 1, errorMargin);
}

TEST(CameraTests, LookAt_SetPerspective_Default)
{
   Camera camera("TestCam");

   const Angle fovY = 60.0_deg;
   constexpr float aspectRatio = 16.f/9.f;
   camera.SetPerspectiveProjection(fovY, aspectRatio);
   const auto camMatrix = camera.GetViewProjectionMatrix();

   Matrix4x4 expectedMatrix = Matrix4x4::Identity();

   const float cotHalfFov = 1.f / std::tan(fovY * 0.5f);
   constexpr float near = 0.1f;
   constexpr float farMinusNear = 1000.f - near;
   expectedMatrix[0] = cotHalfFov / aspectRatio;
   expectedMatrix[5] = cotHalfFov;
   expectedMatrix[10] = -(1000.f + near) / farMinusNear;
   expectedMatrix[11] = - (2.f * 1000.f * near) / farMinusNear;
   expectedMatrix[14] = -1.f;
   expectedMatrix[15] = 0.f;

   const bool isEqual = camMatrix.Equals(expectedMatrix, errorMargin);
   EXPECT_TRUE(isEqual);
}
