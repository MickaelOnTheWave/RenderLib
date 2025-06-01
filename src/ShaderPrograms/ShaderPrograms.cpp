#include "ShaderPrograms.h"

SimpleTexturingProgram::SimpleTexturingProgram()
  : ShaderProgram(std::string(DATA_PATH) + "/basic.vert", std::string(DATA_PATH) +"/singleTexture.frag")
{
}

void SimpleTexturingProgram::use()
{
   ShaderProgram::use();
   glUniform1i(glGetUniformLocation(GetId(), "colorTexture"), 0);
}

PhongLightingProgram::PhongLightingProgram()
  : ShaderProgram(std::string(DATA_PATH) + "/phong.vert", std::string(DATA_PATH) + "/phong.frag")
{
}

void PhongLightingProgram::use()
{
   ShaderProgram::use();
   glUniform3f(glGetUniformLocation(GetId(), "lightColor"), 1.0f, 1.0f, 1.0f);
}

TestingProgram::TestingProgram()
   : ShaderProgram(std::string(DATA_PATH) +"/basic.vert", std::string(DATA_PATH) + "/basic.frag")
{
}

void ObjectColorProgram::use()
{
   ShaderProgram::use();
}

ProceduralEyeProgram::ProceduralEyeProgram()
   : ShaderProgram(std::string(DATA_PATH) + "/basic.vert", std::string(DATA_PATH) + "/eye.frag")
{
}

void ProceduralEyeProgram::use()
{
   ShaderProgram::use();
}

void TestingProgram::use()
{
   ShaderProgram::use();
   glUniform1i(glGetUniformLocation(GetId(), "texture1"), 0);
   glUniform1i(glGetUniformLocation(GetId(), "texture2"), 1);
}


ObjectColorProgram::ObjectColorProgram()
  : ShaderProgram(std::string(DATA_PATH) + "/basic.vert", std::string(DATA_PATH) + "/basiccolor.frag")
{
}
