#ifndef GLGEOMETRY_H
#define GLGEOMETRY_H

#include <vector>

class GlGeometry
{
public:
   GlGeometry();

   unsigned int sceneId;
   unsigned int vertexBufferObject;
   unsigned int elementBufferObject;
   unsigned int vertexArrayObject;

private:
   virtual std::vector<float> CreateVertexBufferData() const = 0;
   virtual std::vector<unsigned int> CreateIndexData() const = 0;

   void setupVertexBufferObject();
   void setupElementBufferObject();
};

#endif // GLGEOMETRY_H
