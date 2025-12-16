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

/**
 * @brief OpenGL Implementation of Renderer.
 * Typical usage :
 * 1. Setup Renderer :
 *  a. Create Renderer
 *  b. Add camera
 *  c. Add Shader programs to use in the renderer
 *  d. Add materials / textures that scene objects will use
 *  e. Add scene objects
 *  f. Call PrepareRendering()
 * 2. Render : call Render().
 */
class GlRenderer
{
public:
   enum class ShaderEnum {
       SIMPLE_TEXTURING = 0,
       PHONG_LIGHTING,
       OBJECT_COLOR_ONLY,
       TESTING,
       PROCEDURAL_EYE
   };

   GlRenderer(AbstractGlCamera *_camera = nullptr);
   virtual ~GlRenderer();

   std::vector<int> Initialize(const std::vector<ShaderProgram*>& _shaderPrograms);

   void SetCamera(AbstractGlCamera *newCamera);
   void SetCurrentShader(const unsigned int shaderId);
   void SetClearColor(const float r, const float g, const float b);

   unsigned int AddTexture(const std::string& file, const int colorChannels);
   unsigned int AddTexture(const ImageData& image, const int glFormat = 0);
   unsigned int AddTexture(const Vector3& color);
   std::vector<unsigned int> GetTextures() const;


   void AddMaterial(Material* material);
   std::vector<Material*> GetMaterials();

   void AddRenderObject(GlRenderedInstance* object);
   void AddRenderObject(GlRenderedInstance* object, const unsigned int shaderId);

   std::vector<GlRenderObject*> ComputeRenderObjectsList() const;
   std::vector<GlRenderedInstance*> ComputeInstancesList() const;

   void PrepareRendering();

   void Render();

   bool HasError() const;
   std::string GetError() const;

   void SetTempLights(Vector3* position, Vector3* color);


private:
   using RenderObjectsMap = std::unordered_map<GlRenderObject*, std::vector<GlRenderedInstance*>>;

   void ClearScene();
   void ClearMaterials();

   void AddRenderObject(GlRenderedInstance* object, ShaderProgram* shader);
   void AddToObjectMap(GlRenderedInstance* object, RenderObjectsMap& objectMap);

   AbstractGlCamera* camera;
   std::map<unsigned int, std::shared_ptr<ShaderProgram>> shaderPrograms;
   ShaderProgram* activeShaderProgram = nullptr;

   // Used as a reference. Objects are stored in the RenderObjects map.
   std::map<ShaderProgram*, RenderObjectsMap> renderObjectsPerShader;

   // Used for storage.
   RenderObjectsMap renderObjectsStorage;

   std::vector<Material*> materials;

   TextureManager textureManager;

   float clearColorR, clearColorG, clearColorB;

   std::vector<std::string> initErrors;
   std::vector<std::string> renderErrors;

   //Temp
   Vector3* lightPosition = nullptr;
   Vector3* lightColor = nullptr;
};

#endif // GLRENDERER_H
