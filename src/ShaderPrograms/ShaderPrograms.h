#ifndef SHADERPROGRAMS_H
#define SHADERPROGRAMS_H

#include "ShaderProgram.h"

class SimpleTexturingProgram : public ShaderProgram
{
public:
   SimpleTexturingProgram();
   virtual ~SimpleTexturingProgram() = default;

   void use() override;
};

class PhongLightingProgram : public ShaderProgram
{
public:
   PhongLightingProgram();
   virtual ~PhongLightingProgram() = default;

   void use() override;
};

class ObjectColorProgram : public ShaderProgram
{
   public:
   ObjectColorProgram();
   virtual ~ObjectColorProgram() = default;

   void use() override;
};


class TestingProgram : public ShaderProgram
{
public:
   TestingProgram();
   virtual ~TestingProgram() = default;

   void use() override;
};

#endif // SHADERPROGRAMS
