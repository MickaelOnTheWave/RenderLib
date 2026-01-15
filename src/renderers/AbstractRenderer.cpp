#include "AbstractRenderer.h"

void AbstractRenderer::SetClearColor(const float r, const float g, const float b)
{
   clearColor = Vector3(r, g, b);
}

bool AbstractRenderer::HasError() const
{
   return !initErrors.empty() || !renderErrors.empty();
}

std::string AbstractRenderer::GetError() const
{
   if (!initErrors.empty())
      return initErrors.back();
   else if (!renderErrors.empty())
      return renderErrors.back();
   return "";
}
