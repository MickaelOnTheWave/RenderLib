#ifndef GLRENDERER_H
#define GLRENDERER_H

#include <unordered_map>
#include <map>
#include <memory>

#include "cameras/AbstractGlCamera.h"
#include "ShaderPrograms/ShaderProgram.h"
#include "objects/GlRenderedInstance.h"
#include "objects/GlRenderObject.h"
#include "ImageData.h"
#include "Material.h"
#include "TextureManager.h"

class GlRenderer
{
public:
   enum class ShaderEnum {
       SIMPLE_TEXTURING = 0,
       PHONG_LIGHTING,
       OBJECT_COLOR_ONLY,
       TESTING
   };

   GlRenderer(AbstractGlCamera *_camera);
   virtual ~GlRenderer();

   void SetCamera(AbstractGlCamera *newCamera);
   void SetRenderShader(const ShaderEnum& renderMode);
   void SetClearColor(const float r, const float g, const float b);

   unsigned int AddTexture(const std::string& file, const int colorChannels);
   unsigned int AddTexture(const ImageData& image);
   unsigned int AddTexture(const Vector3& color);
   void AddMaterial(Material* material);

   void AddRenderObject(GlRenderedInstance* object);
   void AddRenderObject(GlRenderedInstance* object, const ShaderEnum& shader);

   void PrepareRendering();

   void Render();

   void SetTempLights(Vector3* position, Vector3* color);


private:
   using RenderObjectsMap = std::unordered_map<GlRenderObject*, std::vector<GlRenderedInstance*>>;

   void ClearScene();
   void ClearMaterials();

   void AddRenderObject(GlRenderedInstance* object, ShaderProgram* shader);
   void AddToObjectMap(GlRenderedInstance* object, RenderObjectsMap& objectMap);

   AbstractGlCamera* camera;
   std::map<ShaderEnum, std::unique_ptr<ShaderProgram>> shaderPrograms;
   ShaderProgram* activeShaderProgram = nullptr;

   // Used as a reference. Objects are stored in the RenderObjects map.
   std::map<ShaderProgram*, RenderObjectsMap> renderObjectsPerShader;

   // Used for storage.
   RenderObjectsMap renderObjectsStorage;

   std::vector<Material*> materials;

   TextureManager textureManager;

   float clearColorR, clearColorG, clearColorB;

   //Temp
   Vector3* lightPosition = nullptr;
   Vector3* lightColor = nullptr;
};

#endif // GLRENDERER_H
