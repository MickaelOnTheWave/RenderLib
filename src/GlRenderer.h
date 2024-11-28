#ifndef GLRENDERER_H
#define GLRENDERER_H

#include <unordered_map>
#include <map>
#include <memory>

#include "cameras/AbstractGlCamera.h"
#include "ShaderProgram.h"
#include "objects/GlRenderedInstance.h"
#include "objects/GlRenderObject.h"

class GlRenderer
{
public:
   enum class RenderMode {
       SIMPLE_TEXTURING = 0,
       SIMPLE_LIGHTING,
       TESTING
   };

   GlRenderer(AbstractGlCamera& _camera);
   virtual ~GlRenderer();

   void ClearScene();

   void SetRenderMode(const RenderMode& renderMode);
   void SetClearColor(const float r, const float g, const float b);

   void AddRenderObject(GlRenderedInstance* object);

   void PrepareRendering();

   void Render();

private:
   AbstractGlCamera& camera;
   std::unordered_map<GlRenderObject*, std::vector<GlRenderedInstance*>> renderObjects;
   std::map<RenderMode, std::unique_ptr<ShaderProgram>> shaderPrograms;
   ShaderProgram* activeShaderProgram = nullptr;

   float clearColorR, clearColorG, clearColorB;
};

#endif // GLRENDERER_H
