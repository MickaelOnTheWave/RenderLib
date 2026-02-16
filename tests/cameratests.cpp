#include <gtest/gtest.h>

#include "scene/resources/Camera.h"

const float errorMargin = 0.0001f;

TEST(CameraTests, LookAt)
{
   Camera camera("TestCam");

   const Vector3 origin(0, 0, 0);
   const Vector3 yAxis(0, 1, 0);

   {
      camera.LookAt(origin, Vector3(0,0,-1), yAxis);
      const auto camMatrix = camera.GetViewProjectionMatrix();
      const bool isIdentity = camMatrix.Equals(Matrix4x4::Identity(), errorMargin);
      EXPECT_TRUE(isIdentity);
   }

   {
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
}
