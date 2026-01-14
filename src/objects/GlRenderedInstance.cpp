#include "GlRenderedInstance.h"

GlRenderedInstance::GlRenderedInstance(GlRenderObject *_object, const Matrix4x4 &_transform,
                                       const std::string& _name)
    : EngineEntity(_name), renderObject(_object), transform(_transform)
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

Vector3 GlRenderedInstance::GetColor() const
{
   return color;
}

void GlRenderedInstance::SetTransform(const Matrix4x4 &newTransform)
{
   transform = newTransform;
}

void GlRenderedInstance::ComposeTransform(const Matrix4x4 &newTransform)
{
   transform *= newTransform;
}

void GlRenderedInstance::SetColor(const Vector3 &_color)
{
   color = _color;
}
