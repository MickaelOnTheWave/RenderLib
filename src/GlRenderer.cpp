#include "GlRenderer.h"

GlRenderer::GlRenderer(AbstractGlCamera& _camera)
   : camera(_camera), shaderProgram("data/basic.vert", "data/basic.frag")
{
   glViewport(0, 0, 1024, 768);
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
   shaderProgram.use();
   glUniform1i(glGetUniformLocation(shaderProgram.GetId(), "texture1"), 0);
   glUniform1i(glGetUniformLocation(shaderProgram.GetId(), "texture2"), 1);
}

void GlRenderer::Render()
{
   glClearColor(clearColorR, clearColorG, clearColorB, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
      for (const auto& renderObj : renderObjects)
      {
         unsigned int transformLoc = glGetUniformLocation(shaderProgram.GetId(), "cameraTransform");
         glUniformMatrix4fv(transformLoc, 1, GL_FALSE, camera.getTransformMatrix().getData());

         renderObj.first->PrepareRendering(shaderProgram.GetId());

         for (const auto renderedObj : renderObj.second)
         {
            unsigned int objTransformLoc = glGetUniformLocation(shaderProgram.GetId(), "objectTransform");
            glUniformMatrix4fv(objTransformLoc, 1, GL_FALSE, renderedObj->GetTransform().getData());
            renderObj.first->Render();
         }
      }

   glPopMatrix();
}
