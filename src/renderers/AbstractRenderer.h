#ifndef ABSTRACTRENDERER_H
#define ABSTRACTRENDERER_H

#include <string>
#include <vector>

#include "math/Vector3.h"
#include "scene/Scene.h"

class AbstractRenderer
{
public:
   AbstractRenderer() = default;

   virtual void Initialize() = 0;
   virtual void Render(const Scene& scene) = 0;

   void SetClearColor(const float r, const float g, const float b);

   bool HasError() const;
   std::string GetError() const;

protected:
   Vector3 clearColor;
   std::vector<std::string> initErrors;
   std::vector<std::string> renderErrors;
};

#endif // ABSTRACTRENDERER_H
