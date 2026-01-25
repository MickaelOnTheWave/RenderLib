#include "GlslShaderProgram.h"

#include <glad/gl.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>

GlslShaderProgram::GlslShaderProgram( const std::string& vertexFile, const std::string& fragmentFile,
                              const std::string& _name)
   : EngineEntity(_name), vertexShaderFile(vertexFile), fragmentShaderFile(fragmentFile)
{
}

GlslShaderProgram::~GlslShaderProgram()
{
   free(vertexShaderDataPtr);
   vertexShaderDataPtr = nullptr;
   free(fragmentShaderDataPtr);
   fragmentShaderDataPtr = nullptr;
}

bool GlslShaderProgram::Initialize()
{
   const bool vertexShaderOk = prepareShader(vertexShader, &vertexShaderDataPtr, vertexShaderFile, GL_VERTEX_SHADER);
   const bool fragmentShaderOk = prepareShader(fragmentShader, &fragmentShaderDataPtr, fragmentShaderFile, GL_FRAGMENT_SHADER);
   const bool shaderLinkOk = initializeShaderProgram();
   return (vertexShaderOk && fragmentShaderOk && shaderLinkOk);
}

unsigned int GlslShaderProgram::GetId() const
{
   return shaderProgram;
}

void GlslShaderProgram::use()
{
   glUseProgram(shaderProgram);
}

void GlslShaderProgram::SetUniformInt(const std::string &varName, const int value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniform1i(varLocation, value);
}

void GlslShaderProgram::SetUniformFloat(const std::string &varName, const float value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniform1f(varLocation, value);
}

void GlslShaderProgram::SetUniformMat4(const std::string &varName, const Matrix4x4 &value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniformMatrix4fv(varLocation, 1, GL_FALSE, value.GetData());
}

void GlslShaderProgram::SetUniformVec3(const std::string &varName, const Vector3 &value)
{
   SetUniformVec3(varName, value.GetData());
}

void GlslShaderProgram::SetUniformVec3(const std::string &varName, const std::vector<float> &value)
{
   unsigned int varLocation = glGetUniformLocation(GetId(), varName.c_str());
   glUniform3fv(varLocation, 1, &value[0]);
}

void GlslShaderProgram::SetUniformMaterial(const GlMaterial* material)
{
   SetUniformInt("diffuseTexture", material->glDiffuseTexture->glTextureId);
   SetUniformInt("specularTexture", material->glSpecularTexture->glTextureId);
   SetUniformFloat("shininess", material->shininess);
}

std::vector<std::string> GlslShaderProgram::GetErrors() const
{
   return errors;
}

bool GlslShaderProgram::prepareShader(unsigned int& shader, char** shaderData,
                               const std::string& shaderFile, unsigned int shaderType)
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
   glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
   if(!success)
   {
       glGetShaderInfoLog(shader, 512, NULL, infoLog);
       std::stringstream errorLog;
       errorLog << "SHADER compilation of " << shaderFile << " failed : " << infoLog << std::endl;
       errors.push_back(errorLog.str());
   }
   return (success != 0);
}

bool GlslShaderProgram::initializeShaderProgram()
{
   shaderProgram = glCreateProgram();
   glAttachShader(shaderProgram, vertexShader);
   glAttachShader(shaderProgram, fragmentShader);
   glLinkProgram(shaderProgram);

   int  success;
   char infoLog[512];
   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
   if(!success)
   {
       glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
       std::stringstream errorLog;
       errorLog << "SHADER linking failed : " << infoLog << std::endl;
       errors.push_back(errorLog.str());
   }

   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);

   return (success != 0);
}
