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
   Vector3 GetColor() const;

   void SetTransform(const Matrix4x4& newTransform);
   void ComposeTransform(const Matrix4x4& newTransform);
   void SetColor(const Vector3& _color);

private:
   GlRenderObject* renderObject;
   Matrix4x4 transform;
   Vector3 color;
};

#endif // GLRENDEREDINSTANCE_H
