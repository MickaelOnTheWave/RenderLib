#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

struct Texture
{
   Texture() = default;
   Texture(const std::string& _file, const int _format);

   std::string file;
   int format;
};

class Material
{
public:
   Material(const std::string& _name);
   Material(const Material& other);

   std::string name;

   unsigned int diffuseTextureId;
   unsigned int specularTextureId;
   float shininess;
};

#endif // MATERIAL_H
