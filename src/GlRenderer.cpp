#include "GlRenderer.h"

GlRenderer::GlRenderer(AbstractGlCamera& _camera)
   : camera(_camera)
{
   shaderPrograms[ShaderEnum::SIMPLE_TEXTURING] = std::make_unique<ShaderProgram>("data/basic.vert", "data/singleTexture.frag");
   shaderPrograms[ShaderEnum::SIMPLE_LIGHTING]  = std::make_unique<ShaderProgram>("data/basiclighting.vert", "data/basiclighting.frag");
   shaderPrograms[ShaderEnum::TESTING]          = std::make_unique<ShaderProgram>("data/basic.vert", "data/basic.frag");

   SetRenderShader(ShaderEnum::TESTING);

   for (const auto& shader : shaderPrograms)
      renderObjectsPerShader[shader.second.get()] = RenderObjectsMap();
}

GlRenderer::~GlRenderer()
{
   ClearScene();
}

void GlRenderer::ClearScene()
{
   for (auto& renderObjPerShader : renderObjectsPerShader)
   {
      for (auto& renderObjs : renderObjPerShader.second)
      {
         for (auto* renderInstance : renderObjs.second)
         {
            delete renderInstance;
         }
         renderObjs.second.clear();
         delete renderObjs.first;
      }
      renderObjPerShader.second.clear();
   }

   renderObjectsPerShader.clear();
}

void GlRenderer::SetRenderShader(const ShaderEnum &renderMode)
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
   AddRenderObject(object, activeShaderProgram);
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object, const ShaderEnum &shader)
{
   ShaderProgram* renderObjectShader = shaderPrograms[shader].get();
   if (!renderObjectShader)
      renderObjectShader = activeShaderProgram;
   AddRenderObject(object, renderObjectShader);
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

   for (const auto& shaderRenderObj : renderObjectsPerShader)
   {
      if (shaderRenderObj.second.empty())
         continue;

      ShaderProgram* currentShader = shaderRenderObj.first;

      unsigned int transformLoc = glGetUniformLocation(currentShader->GetId(), "cameraTransform");
      glUniformMatrix4fv(transformLoc, 1, GL_FALSE, camera.getTransformMatrix().getData());

      const std::vector<float> lightColor = {1.f, 1.0f, 1.f};
      unsigned int lightColorLoc = glGetUniformLocation(currentShader->GetId(), "lightColor");
      glUniform3fv(lightColorLoc, 1, &lightColor[0]);

      glPushMatrix();
         for (const auto& renderObj : shaderRenderObj.second)
         {
            const std::vector<float> objectColor = {1.f, 1.f, 0.f};
            unsigned int objectColorLoc = glGetUniformLocation(currentShader->GetId(), "objectColor");
            glUniform3fv(objectColorLoc, 1, &objectColor[0]);


            renderObj.first->PrepareRendering(currentShader->GetId());

            for (const auto renderedObj : renderObj.second)
            {
               unsigned int objTransformLoc = glGetUniformLocation(currentShader->GetId(), "objectTransform");
               glUniformMatrix4fv(objTransformLoc, 1, GL_FALSE, renderedObj->GetTransform().getData());
               renderObj.first->Render();
            }
         }

      glPopMatrix();
   }
}

void GlRenderer::AddRenderObject(GlRenderedInstance *object, ShaderProgram *shader)
{
   RenderObjectsMap& renderObjectMap = renderObjectsPerShader[shader];

   auto renderObjIt = renderObjectMap.find(object->GetRenderObject());
   if (renderObjIt != renderObjectMap.end())
      renderObjIt->second.push_back(object);
   else
      renderObjectMap[object->GetRenderObject()] = {object};
}
