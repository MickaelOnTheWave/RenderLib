#ifndef GLMODEL_H
#define GLMODEL_H

#include <memory>
#include <vector>

#include "GlGeometry.h"
#include "GlMaterial.h"
#include "GlslShaderProgram.h"

class GlModelPart
{
public:
   void PrepareRendering(std::unique_ptr<GlslShaderProgram>& currentShader) const;
   void Render() const;

   const GlGeometry* glGeometry;
   const GlMaterial* glMaterial;
};

class GlModel
{
public:
   GlModel();

   unsigned int sceneId;
   std::vector<GlModelPart> modelParts;
};

#endif // GLMODEL_H
