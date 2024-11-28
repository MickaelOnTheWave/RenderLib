#include "GlRenderer.h"

GlRenderer::GlRenderer(AbstractGlCamera& _camera)
   : camera(_camera)
{
   shaderPrograms[RenderMode::SIMPLE_TEXTURING] = std::make_unique<ShaderProgram>("data/basic.vert", "data/singleTexture.frag");
   shaderPrograms[RenderMode::SIMPLE_LIGHTING]  = std::make_unique<ShaderProgram>("data/basiclighting.vert", "data/basiclighting.frag");
   shaderPrograms[RenderMode::TESTING]          = std::make_unique<ShaderProgram>("data/basic.vert", "data/basic.frag");

   SetRenderMode(RenderMode::TESTING);
}

GlRenderer::~GlRenderer()
{
   ClearScene();
}

void GlRenderer::ClearScene()
{
   for (auto& renderObj : renderObjects)
   {
      for (const auto renderedObj : renderObj.second)
      {
         delete renderedObj;
      }
      renderObj.second.clear();
      delete renderObj.first;
   }
   renderObjects.clear();
}

void GlRenderer::SetRenderMode(const RenderMode &renderMode)
{
   activeShaderProgram = shaderPrograms[renderMode].get();
}

void GlRenderer::SetClearColor(const float r, const float g, const float b)
{
   clearColorR = r;
   clearColorG = g;
   clearColorB = b;
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object)
{
   renderObjects[object->GetRenderObject()].push_back(object);
}

void GlRenderer::PrepareRendering()
{
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glEnable(GL_DEPTH_TEST);
   activeShaderProgram->use();
   glUniform1i(glGetUniformLocation(activeShaderProgram->GetId(), "texture1"), 0);
   glUniform1i(glGetUniformLocation(activeShaderProgram->GetId(), "texture2"), 1);
}

void GlRenderer::Render()
{
   glClearColor(clearColorR, clearColorG, clearColorB, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
      for (const auto& renderObj : renderObjects)
      {
         unsigned int transformLoc = glGetUniformLocation(activeShaderProgram->GetId(), "cameraTransform");
         glUniformMatrix4fv(transformLoc, 1, GL_FALSE, camera.getTransformMatrix().getData());

         renderObj.first->PrepareRendering(activeShaderProgram->GetId());

         for (const auto renderedObj : renderObj.second)
         {
            unsigned int objTransformLoc = glGetUniformLocation(activeShaderProgram->GetId(), "objectTransform");
            glUniformMatrix4fv(objTransformLoc, 1, GL_FALSE, renderedObj->GetTransform().getData());
            renderObj.first->Render();
         }
      }

   glPopMatrix();
}
