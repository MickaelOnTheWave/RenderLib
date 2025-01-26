#include "SphereTextureMappings.h"

SphereTextureMapping::SphereTextureMapping(std::vector<TexCoord> &_textureCoordinates,
                                           const SphereTexturingData& _texturingData)
  : textureCoordinates(_textureCoordinates), texturingData(_texturingData)
{
}

/******/

FullWrapSphereMapping::FullWrapSphereMapping(std::vector<TexCoord> &_textureCoordinates,
                                             const SphereTexturingData& _texturingData)
  : SphereTextureMapping(_textureCoordinates, _texturingData)
{
}

void FullWrapSphereMapping::MapTop()
{
   textureCoordinates.emplace_back(0.5f, 0.f);
}

void FullWrapSphereMapping::Map(const SphereTexturingIndex& index)
{
   const float u = static_cast<float>(index.horizontal) / texturingData.horizontalCount;
   const float v = static_cast<float>(index.vertical) / texturingData.verticalCount;
   textureCoordinates.emplace_back(u, v);
}

void FullWrapSphereMapping::MapBottom()
{
   textureCoordinates.emplace_back(0.5f, 1.f);
}

/******/

HalfWrapSphereMapping::HalfWrapSphereMapping(std::vector<TexCoord> &_textureCoordinates,
                                             const SphereTexturingData& _texturingData)
  : FullWrapSphereMapping(_textureCoordinates, _texturingData)
{
}

void HalfWrapSphereMapping::Map(const SphereTexturingIndex& index)
{
   const float minU = 0.25f;
   const float maxU = 0.75f;
   float u = static_cast<float>(index.horizontal) / texturingData.horizontalCount;
   if (u < minU)
      u = 0.f;
   else if (u > maxU)
      u = 1.f;
   else
      u = (u - minU) * 2.f;


   const float v = static_cast<float>(index.vertical) / texturingData.verticalCount;
   textureCoordinates.emplace_back(u, v);
}

/******/

HalfPolarProjectionSphereMapping::HalfPolarProjectionSphereMapping(std::vector<TexCoord> &_textureCoordinates,
                                                                   const SphereTexturingData& _texturingData)
  : SphereTextureMapping(_textureCoordinates, _texturingData)
{
}

void HalfPolarProjectionSphereMapping::MapTop()
{
   textureCoordinates.emplace_back(0.5f, 0.5f);
}

void HalfPolarProjectionSphereMapping::Map(const SphereTexturingIndex& index)
{
   const float u = index.vertex.X();
   const float v = index.vertex.Z();
   textureCoordinates.emplace_back(u, v);
}

void HalfPolarProjectionSphereMapping::MapBottom()
{
   textureCoordinates.emplace_back(0.5f, 0.5f);
}
