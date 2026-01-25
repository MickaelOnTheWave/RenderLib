#ifndef GLSLSHADERPROGRAM_H
#define GLSLSHADERPROGRAM_H

#include "EngineEntity.h"

#include <string>
#include "math/Matrix4x4.h"
#include "math/Vector3.h"
#include "renderers/opengl/GlMaterial.h"

class GlslShaderProgram : public EngineEntity
{
public:
   GlslShaderProgram(const std::string& vertexFile, const std::string& fragmentFile,
                 const std::string& _name = "Unnamed Shader");
   virtual ~GlslShaderProgram();

   bool Initialize();

   unsigned int GetId() const;
   virtual void use();

   void SetUniformInt(const std::string& varName, const int value);
   void SetUniformFloat(const std::string& varName, const float value);
   void SetUniformMat4(const std::string& varName, const Matrix4x4& value);
   void SetUniformVec3(const std::string& varName, const Vector3& value);
   void SetUniformVec3(const std::string& varName, const std::vector<float>& value);
   void SetUniformMaterial(const GlMaterial* material);

   std::vector<std::string> GetErrors() const;

private:
   bool prepareShader(unsigned int& shader, char** shaderData,
                      const std::string& shaderFile, unsigned int shaderType);
   bool initializeShaderProgram();

   char* vertexShaderDataPtr;
   unsigned int vertexShader;

   char* fragmentShaderDataPtr;
   unsigned int fragmentShader;

   unsigned int shaderProgram;

   // TODO : refactor that. This class should handle only the content,
   // file reading should be done in a separate util.
   std::string vertexShaderFile;
   std::string fragmentShaderFile;

   std::vector<std::string> errors;
};

#endif // GLSLSHADERPROGRAM_H
