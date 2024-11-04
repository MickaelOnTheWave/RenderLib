#include "GlRenderedInstance.h"

GlRenderedInstance::GlRenderedInstance(GlRenderObject *_object, const Matrix4x4 &_transform)
  : renderObject(_object), transform(_transform)
{
}

GlRenderObject *GlRenderedInstance::GetRenderObject() const
{
   return renderObject;
}

Matrix4x4 GlRenderedInstance::GetTransform() const
{
   return transform;
}
