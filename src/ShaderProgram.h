#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <glad/gl.h>
#include <string>

class ShaderProgram
{
public:
   ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile);
   virtual ~ShaderProgram();

   unsigned int GetId() const;
   void use();

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
