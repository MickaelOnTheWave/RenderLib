#include "ShaderPrograms.h"

SimpleTexturingProgram::SimpleTexturingProgram()
  : ShaderProgram("data/basic.vert", "data/singleTexture.frag")
{
}

void SimpleTexturingProgram::use()
{
   ShaderProgram::use();
   glUniform1i(glGetUniformLocation(GetId(), "colorTexture"), 0);
}

PhongLightingProgram::PhongLightingProgram()
  : ShaderProgram("data/phong.vert", "data/phong.frag")
{
}

void PhongLightingProgram::use()
{
   ShaderProgram::use();
   glUniform3f(glGetUniformLocation(GetId(), "lightColor"), 1.0f, 1.0f, 1.0f);
}

TestingProgram::TestingProgram()
   : ShaderProgram("data/basic.vert", "data/basic.frag")
{
}

void TestingProgram::use()
{
   ShaderProgram::use();
   glUniform1i(glGetUniformLocation(GetId(), "texture1"), 0);
   glUniform1i(glGetUniformLocation(GetId(), "texture2"), 1);
}


ObjectColorProgram::ObjectColorProgram()
  : ShaderProgram("data/basic.vert", "data/basiccolor.frag")
{
}

void ObjectColorProgram::use()
{
   ShaderProgram::use();
}
