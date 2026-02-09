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

std::vector<std::string> AbstractRenderer::GetErrors() const
{
   std::vector<std::string> errors;
   errors.resize(initErrors.size() + renderErrors.size());
   int i =0;
   for (i=0; i<initErrors.size(); ++i)
      errors[i] = initErrors[i];
   for (int j=0; j<renderErrors.size(); ++j, ++i)
      errors[i] = renderErrors[j];
   return errors;
}
