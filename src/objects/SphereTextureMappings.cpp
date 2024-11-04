#include "SphereTextureMappings.h"

SphereTextureMapping::SphereTextureMapping(std::vector<TexCoord> &_textureCoordinates,
                                           const unsigned int horizontalCount,
                                           const unsigned int verticalCount)
  : textureCoordinates(_textureCoordinates), horizontalPointCount(horizontalCount),
  verticalPointCount(verticalCount)
{
}

/******/

FullWrapSphereMapping::FullWrapSphereMapping(std::vector<TexCoord> &_textureCoordinates,
                                             const unsigned int horizontalCount,
                                             const unsigned int verticalCount)
  : SphereTextureMapping(_textureCoordinates, horizontalCount, verticalCount)
{
}

void FullWrapSphereMapping::MapTop()
{
   textureCoordinates.emplace_back(0.5f, 0.f);
}

void FullWrapSphereMapping::Map(const unsigned int verticalIndex, const unsigned int horizontalIndex)
{
   const float u = static_cast<float>(horizontalIndex) / horizontalPointCount;
   const float v = static_cast<float>(verticalIndex) / verticalPointCount;
   textureCoordinates.emplace_back(u, v);
}

void FullWrapSphereMapping::MapBottom()
{
   textureCoordinates.emplace_back(0.5f, 1.f);
}

/******/

HalfWrapSphereMapping::HalfWrapSphereMapping(std::vector<TexCoord> &_textureCoordinates,
                                             const unsigned int horizontalCount,
                                             const unsigned int verticalCount)
  : FullWrapSphereMapping(_textureCoordinates, horizontalCount, verticalCount)
{
}

void HalfWrapSphereMapping::Map(const unsigned int verticalIndex, const unsigned int horizontalIndex)
{
   const float minU = 0.25f;
   const float maxU = 0.75f;
   float u = static_cast<float>(horizontalIndex) / horizontalPointCount;
   if (u < minU)
      u = 0.f;
   else if (u > maxU)
      u = 1.f;
   else
      u = (u - minU) * 2.f;


   const float v = static_cast<float>(verticalIndex) / verticalPointCount;
   textureCoordinates.emplace_back(u, v);
}
