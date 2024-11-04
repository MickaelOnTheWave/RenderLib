#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector3.h"

#include <list>
#include <vector>

struct TexCoord
{
   TexCoord(float _u = 0.f, float _v = 0.f) : u(_u), v(_v)
   {}

   TexCoord Middle(const TexCoord& other)
   {
      TexCoord middle;
      middle.u = (u + other.u) / 2.f;
      middle.v = (v + other.v) / 2.f;
      return middle;
   }

   float u,v;
};

class Triangle
{
public:
   Triangle(const unsigned int _indexP1, const unsigned int _indexP2,
            const unsigned int _indexP3);


   unsigned int GetP1() const;
   unsigned int GetP2() const;
   unsigned int GetP3() const;

   void Subdivide(std::vector<Vector3>& pointRepository,
                  std::vector<TexCoord> &textureCoordinateRepository,
                  std::list<Triangle> &triangleRepository,
                  std::list<Triangle>::iterator currentTriangleIt) const;

private:
   void MovePointToSphere(Vector3* point) const;

   unsigned int indexP1;
   unsigned int indexP2;
   unsigned int indexP3;
};

#endif // TRIANGLE_H
