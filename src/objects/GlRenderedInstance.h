#ifndef GLRENDEREDINSTANCE_H
#define GLRENDEREDINSTANCE_H

#include "GlRenderObject.h"
#include "math/Matrix4x4.h"

class GlRenderedInstance
{
public:
   GlRenderedInstance(GlRenderObject* _object,
                     const Matrix4x4& _transform);

   GlRenderObject* GetRenderObject() const;
   Matrix4x4 GetTransform() const;

private:
   GlRenderObject* renderObject;
   Matrix4x4 transform;
};

#endif // GLRENDEREDINSTANCE_H
