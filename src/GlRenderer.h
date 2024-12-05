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
   enum class ShaderEnum {
       SIMPLE_TEXTURING = 0,
       SIMPLE_LIGHTING,
       OBJECT_COLOR_ONLY,
       TESTING
   };

   GlRenderer(AbstractGlCamera& _camera);
   virtual ~GlRenderer();

   void ClearScene();

   void SetRenderShader(const ShaderEnum& renderMode);
   void SetClearColor(const float r, const float g, const float b);

   void AddRenderObject(GlRenderedInstance* object);
   void AddRenderObject(GlRenderedInstance* object, const ShaderEnum& shader);

   void PrepareRendering();

   void Render();


private:
   void AddRenderObject(GlRenderedInstance* object, ShaderProgram* shader);

   using RenderObjectsMap = std::unordered_map<GlRenderObject*, std::vector<GlRenderedInstance*>>;
   AbstractGlCamera& camera;
   std::map<ShaderProgram*, RenderObjectsMap> renderObjectsPerShader;
   std::map<ShaderEnum, std::unique_ptr<ShaderProgram>> shaderPrograms;
   ShaderProgram* activeShaderProgram = nullptr;

   float clearColorR, clearColorG, clearColorB;
};

#endif // GLRENDERER_H
