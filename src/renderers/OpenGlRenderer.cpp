#include "OpenGlRenderer.h"

#include <glad/gl.h>

OpenGlRenderer::OpenGlRenderer()
: polygonMode(GL_FILL)
{
}

void OpenGlRenderer::Initialize()
{

}

void OpenGlRenderer::PrepareRenderPass()
{
   glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
   glEnable(GL_DEPTH_TEST);

   //glEnable(GL_CULL_FACE);
   //glCullFace(GL_BACK);

   if (activeShaderProgram)
      activeShaderProgram->use();
   else
      initErrors.emplace_back("Can't prepare rendering : No active Shader Program.");
}

void OpenGlRenderer::Render(const Scene& scene)
{

}

void OpenGlRenderer::EnableWireframeMode(const bool enable)
{
   polygonMode = enable ? GL_LINE : GL_FILL;
}
