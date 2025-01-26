#ifndef SPHERETEXTUREMAPPINGS_H
#define SPHERETEXTUREMAPPINGS_H

#include <vector>

#include "math/Triangle.h"

struct SphereTexturingData
{
   SphereTexturingData(const unsigned int _horizontalCount,
                       const unsigned int _verticalCount,
                       const float _scalingU, const float _scalingV)
     : horizontalCount(_horizontalCount),
     verticalCount(_verticalCount),
     scalingU(_scalingU), scalingV(_scalingV)
   {
   }

   unsigned int horizontalCount;
   unsigned int verticalCount;
   float scalingU;
   float scalingV;
};

struct SphereTexturingIndex
{
   SphereTexturingIndex(const unsigned int _horizontal,
                        const unsigned int _vertical,
                        const Vector3& _vertex)
     : horizontal(_horizontal), vertical(_vertical),
     vertex(_vertex)
   {
   }

   unsigned int horizontal;
   unsigned int vertical;
   Vector3 vertex;
};

class SphereTextureMapping
{
public:
   SphereTextureMapping(std::vector<TexCoord>& _textureCoordinates,
                        const SphereTexturingData& _texturingData);
   virtual ~SphereTextureMapping() = default;

   virtual void MapTop() = 0;
   virtual void Map(const SphereTexturingIndex& index) = 0;
   virtual void MapBottom() = 0;

protected:
   SphereTexturingData texturingData;
   std::vector<TexCoord>& textureCoordinates;
};

class FullWrapSphereMapping : public SphereTextureMapping
{
public :
   FullWrapSphereMapping(std::vector<TexCoord>& _textureCoordinates,
                         const SphereTexturingData& _texturingData);
   virtual ~FullWrapSphereMapping() = default;

   void MapTop() override;
   void Map(const SphereTexturingIndex& index) override;
   void MapBottom() override;
};

class HalfWrapSphereMapping : public FullWrapSphereMapping
{
   public :
   HalfWrapSphereMapping(std::vector<TexCoord>& _textureCoordinates,
                         const SphereTexturingData& _texturingData);
   virtual ~HalfWrapSphereMapping() = default;

   void Map(const SphereTexturingIndex& index) override;
};

class HalfPolarProjectionSphereMapping : public SphereTextureMapping
{
public :
   HalfPolarProjectionSphereMapping(std::vector<TexCoord>& _textureCoordinates,
                                    const SphereTexturingData& _texturingData);
   virtual ~HalfPolarProjectionSphereMapping() = default;

   void MapTop() override;
   void Map(const SphereTexturingIndex& index) override;
   void MapBottom() override;

private:
   const float centerX, centerY;
};

#endif // SPHERETEXTUREMAPPINGS_H
