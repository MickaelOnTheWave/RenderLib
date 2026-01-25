#ifndef GLGEOMETRY_H
#define GLGEOMETRY_H

#include <vector>

class GlGeometry
{
public:
   GlGeometry();

   void Initialize();

   unsigned int sceneId;
   unsigned int vertexBufferObject;
   unsigned int elementBufferObject;
   unsigned int vertexArrayObject;

   unsigned int faceCount = 0;

private:
   virtual std::vector<float> CreateVertexBufferData() const = 0;
   virtual std::vector<unsigned int> CreateIndexData() const = 0;

   void CreateVertexBufferObject();
   void CreateElementBufferObject();
   void CreateVertexArrayObject();
};

#endif // GLGEOMETRY_H
