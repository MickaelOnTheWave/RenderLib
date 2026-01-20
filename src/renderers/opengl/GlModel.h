#ifndef GLMODEL_H
#define GLMODEL_H

#include <vector>

#include "GlGeometry.h"
#include "GlMaterial.h"

class GlModel
{
public:
   GlModel();

   struct GlModelPart
   {
      const GlGeometry* glGeometry;
      const GlMaterial* glMaterial;
   };

   unsigned int sceneId;
   std::vector<GlModelPart> modelParts;
};

#endif // GLMODEL_H
