#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glad/gl.h>
#include <string>

#include "math/Matrix4x4.h"
#include "math/Vector3.h"

class ShaderProgram
{
public:
   ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile);
   virtual ~ShaderProgram();

   unsigned int GetId() const;
   virtual void use();

   void SetUniformMat4(const std::string& varName, const Matrix4x4& value);
   void SetUniformVec3(const std::string& varName, const Vector3& value);
   void SetUniformVec3(const std::string& varName, const std::vector<float>& value);

private:
   void prepareShader(unsigned int& shader, char** shaderData,
                      const std::string& shaderFile, GLenum shaderType);
   void initializeShaderProgram();

   char* vertexShaderDataPtr;
   unsigned int vertexShader;

   char* fragmentShaderDataPtr;
   unsigned int fragmentShader;

   unsigned int shaderProgram;
};

#endif // SHADERPROGRAM_H
