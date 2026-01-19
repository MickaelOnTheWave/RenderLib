#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "AbstractRenderer.h"

#include <vector>
#include "renderers/opengl/GlTexture.h"

class OpenGlRenderer : public AbstractRenderer
{
public:
   OpenGlRenderer();

   void Initialize() override;
   void Render(const Scene& scene) override;

   void EnableWireframeMode(const bool enable);

private:
   void PrepareRenderPass();
   void CreateGpuRepresentation(const Scene& scene);
   void UpdateGpuRepresentation(const Scene& scene);

   unsigned int polygonMode;
   bool gpuRepresentationCreated = false;
   std::vector<GlTexture> glTextures;
};

#endif // OPENGLRENDERER_H
