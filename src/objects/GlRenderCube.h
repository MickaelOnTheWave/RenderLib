#ifndef GLRENDERCUBE_H
#define GLRENDERCUBE_H

#include "GlRenderObject.h"

class GlRenderCube : public GlRenderObject
{
public:
    explicit GlRenderCube(Material* _material, const std::string& _name = "");

   void Initialize() override;
   void Render() override;

protected:
   std::vector<float> CreateVertexBufferData() const override;
   std::vector<unsigned int> CreateIndexData() const override;

   void setupVertexBufferObject();
   void setupElementBufferObject();
};

#endif // GLRENDERCUBE_H
