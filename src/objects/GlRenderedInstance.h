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

   void SetTransform(const Matrix4x4& newTransform);
   void ComposeTransform(const Matrix4x4& newTransform);

private:
   GlRenderObject* renderObject;
   Matrix4x4 transform;
};

#endif // GLRENDEREDINSTANCE_H
