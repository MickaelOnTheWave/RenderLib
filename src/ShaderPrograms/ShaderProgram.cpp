#include "ShaderProgram.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>

ShaderProgram::ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile)
{
   prepareShader(vertexShader, &vertexShaderDataPtr, vertexFile, GL_VERTEX_SHADER);
   prepareShader(fragmentShader, &fragmentShaderDataPtr, fragmentFile, GL_FRAGMENT_SHADER);
   initializeShaderProgram();
}

ShaderProgram::~ShaderProgram()
{
   free(vertexShaderDataPtr);
   vertexShaderDataPtr = nullptr;
   free(fragmentShaderDataPtr);
   fragmentShaderDataPtr = nullptr;
}

unsigned int ShaderProgram::GetId() const
{
   return shaderProgram;
}

void ShaderProgram::use()
{
   glUseProgram(shaderProgram);
}

void ShaderProgram::SetUniformInt(const std::string &varName, const int value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniform1i(varLocation, value);
}

void ShaderProgram::SetUniformFloat(const std::string &varName, const float value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniform1f(varLocation, value);
}

void ShaderProgram::SetUniformMat4(const std::string &varName, const Matrix4x4 &value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniformMatrix4fv(varLocation, 1, GL_FALSE, value.GetData());
}

void ShaderProgram::SetUniformVec3(const std::string &varName, const Vector3 &value)
{
   SetUniformVec3(varName, value.GetData());
}

void ShaderProgram::SetUniformVec3(const std::string &varName, const std::vector<float> &value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniform3fv(varLocation, 1, &value[0]);
}

void ShaderProgram::SetUniformMaterial(Material *material)
{
   SetUniformInt("diffuseTexture", 0);
   if (material)
   {
      SetUniformVec3("specularColor", material->specularColor);
      SetUniformFloat("shininess", material->shininess);
   }
   else
   {
      SetUniformVec3("specularColor", Vector3());
      SetUniformFloat("shininess", 0.f);
   }
}

void ShaderProgram::prepareShader(unsigned int& shader, char** shaderData,
                               const std::string& shaderFile, GLenum shaderType)
{
   std::ifstream fileStream;
   fileStream.open(shaderFile);

   std::stringstream buffer;
   buffer << fileStream.rdbuf();
   std::string strBuffer = buffer.str();
   size_t shaderBufferSize = strBuffer.length() * sizeof(char);

   *shaderData = reinterpret_cast<char*>(malloc(shaderBufferSize));
   strncpy(*shaderData, strBuffer.c_str(), strBuffer.length());

   shader = glCreateShader(shaderType);
   glShaderSource(shader, 1, shaderData, reinterpret_cast<GLint*>(&shaderBufferSize));
   glCompileShader(shader);

   int  success;
   char infoLog[512];
   glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
   if(!success)
   {
       glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
       std::cout << "SHADER compilation of " << shaderFile << " failed : " << infoLog << std::endl;
   }

}

void ShaderProgram::initializeShaderProgram()
{
   shaderProgram = glCreateProgram();
   glAttachShader(shaderProgram, vertexShader);
   glAttachShader(shaderProgram, fragmentShader);
   glLinkProgram(shaderProgram);

   int  success;
   char infoLog[512];
   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
   if(!success) {
       glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
       std::cout << "SHADER linking failed : " << infoLog << std::endl;
   }

   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);
}
