#ifndef TEXTURE_H
#define TEXTURE_H

#include "EngineEntity.h"

#include <string>
#include "ImageData.h"

class Texture : public EngineEntity
{
public:
   enum class SourceType
   {
      Undefined = 0,
      File,
      PlainColor,
      Procedural
   };

   Texture(const std::string& _name = "Undefined");
   Texture(const ImageData& _data, const std::string& _source,
           const SourceType& _type,const std::string& _name = "Undefined");
   Texture(const Texture& other);
   virtual ~Texture() = default;

   ImageData& GetData();
   std::string GetSource() const;
   SourceType GetSourceType() const;

private:
   ImageData data;
   std::string source;
   SourceType sourceType;
};

#endif // TEXTURE_H
