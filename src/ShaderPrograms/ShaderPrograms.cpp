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
  : ShaderProgram("data/basiclighting.vert", "data/basiclighting.frag")
{
}

void PhongLightingProgram::use()
{
   ShaderProgram::use();
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
