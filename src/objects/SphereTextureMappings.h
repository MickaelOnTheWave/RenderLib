#ifndef SPHERETEXTUREMAPPINGS_H
#define SPHERETEXTUREMAPPINGS_H

#include <vector>

#include "math/Triangle.h"

class SphereTextureMapping
{
public:
   SphereTextureMapping(std::vector<TexCoord>& _textureCoordinates,
                   const unsigned int horizontalCount, const unsigned int verticalCount);
   virtual ~SphereTextureMapping() = default;

   virtual void MapTop() = 0;
   virtual void Map(const unsigned verticalIndex, const unsigned int horizontalIndex) = 0;
   virtual void MapBottom() = 0;

protected:
   unsigned int horizontalPointCount = 0;
   unsigned int verticalPointCount = 0;
   std::vector<TexCoord>& textureCoordinates;
};

class FullWrapSphereMapping : public SphereTextureMapping
{
public :
   FullWrapSphereMapping(std::vector<TexCoord>& _textureCoordinates,
                        const unsigned int horizontalCount, const unsigned int verticalCount);
   virtual ~FullWrapSphereMapping() = default;

   void MapTop() override;
   void Map(const unsigned verticalIndex, const unsigned int horizontalIndex) override;
   void MapBottom() override;
};

class HalfWrapSphereMapping : public FullWrapSphereMapping
{
   public :
   HalfWrapSphereMapping(std::vector<TexCoord>& _textureCoordinates,
                         const unsigned int horizontalCount, const unsigned int verticalCount);
   virtual ~HalfWrapSphereMapping() = default;

   void Map(const unsigned verticalIndex, const unsigned int horizontalIndex) override;
};


#endif // SPHERETEXTUREMAPPINGS_H
