#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "AbstractRenderer.h"

class OpenGlRenderer : public AbstractRenderer
{
public:
   OpenGlRenderer();

   void Initialize() override;
   void PrepareRenderPass() override;
   void Render(const Scene& scene) override;

   void EnableWireframeMode(const bool enable);

private:
   unsigned int polygonMode;
};

#endif // OPENGLRENDERER_H
