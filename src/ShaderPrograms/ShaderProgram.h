#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>

#include "Material.h"
#include "math/Matrix4x4.h"
#include "math/Vector3.h"

class ShaderProgram
{
public:
   ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile);
   virtual ~ShaderProgram();

   unsigned int GetId() const;
   virtual void use();

   void SetUniformInt(const std::string& varName, const int value);
   void SetUniformFloat(const std::string& varName, const float value);
   void SetUniformMat4(const std::string& varName, const Matrix4x4& value);
   void SetUniformVec3(const std::string& varName, const Vector3& value);
   void SetUniformVec3(const std::string& varName, const std::vector<float>& value);
   void SetUniformMaterial(Material* material);

private:
   void prepareShader(unsigned int& shader, char** shaderData,
                      const std::string& shaderFile, unsigned int shaderType);
   void initializeShaderProgram();

   char* vertexShaderDataPtr;
   unsigned int vertexShader;

   char* fragmentShaderDataPtr;
   unsigned int fragmentShader;

   unsigned int shaderProgram;
};

#endif // SHADERPROGRAM_H
