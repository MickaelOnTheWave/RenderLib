#ifndef GLMODEL_H
#define GLMODEL_H

#include <vector>

#include "GlGeometry.h"
#include "GlMaterial.h"

class GlModelPart
{
public:
   void PrepareRendering() const;
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
