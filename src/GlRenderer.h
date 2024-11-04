#ifndef GLRENDERER_H
#define GLRENDERER_H

#include <unordered_map>
#include <vector>
#include "cameras/AbstractGlCamera.h"
#include "ShaderProgram.h"
#include "objects/GlRenderedInstance.h"
#include "objects/GlRenderObject.h"

class GlRenderer
{
public:
   GlRenderer(AbstractGlCamera& _camera);
   virtual ~GlRenderer();

   void ClearScene();

   void SetClearColor(const float r, const float g, const float b);

   void AddRenderObject(GlRenderedInstance* object);

   void PrepareRendering();

   void Render();

private:
   AbstractGlCamera& camera;
   std::unordered_map<GlRenderObject*, std::vector<GlRenderedInstance*>> renderObjects;
   ShaderProgram shaderProgram;

   float clearColorR, clearColorG, clearColorB;
};

#endif // GLRENDERER_H
