#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "AbstractRenderer.h"

#include "renderers/opengl/GlslShaderProgram.h"
#include "renderers/opengl/GlSceneCache.h"
#include "scene/resources/ModelInstance.h"

class OpenGlRenderer : public AbstractRenderer
{
public:
   OpenGlRenderer();

   bool Initialize() override;
   bool Render(const Scene& scene) override;

   void EnableWireframeMode(const bool enable);

private:
   void PrepareRenderPass();

   void PrepareRendering(const ModelInstance& instance,
                         std::unique_ptr<GlslShaderProgram>& currentShader);

   unsigned int polygonMode;
   bool gpuRepresentationCreated = false;

   GlSceneCache sceneCache;
};

#endif // OPENGLRENDERER_H
