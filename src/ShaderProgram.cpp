#include "ShaderProgram.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>



ShaderProgram::ShaderProgram(const std::string& vertexFile, const std::string& fragmentFile)
{
   prepareShader(vertexShader, &vertexShaderDataPtr, "data/basic.vert", GL_VERTEX_SHADER);
   prepareShader(fragmentShader, &fragmentShaderDataPtr, "data/basic.frag", GL_FRAGMENT_SHADER);
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
