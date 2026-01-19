#include "Texture.h"

Texture::Texture(const std::string& _name)
   : EngineEntity(_name), sourceType(SourceType::Undefined)
{
}

Texture::Texture(const ImageData& _data, const std::string& _source,
                 const SourceType& _type, const std::string& _name)
   : EngineEntity(_name), data(_data), source(_source), sourceType(_type)
{
}

Texture::Texture(const Texture& other)
   : EngineEntity(other), data(other.data),
   source(other.source), sourceType(other.sourceType)
{
}

ImageData& Texture::GetData()
{
   return data;
}

ImageData const& Texture::GetData() const
{
   return data;
}

std::string Texture::GetSource() const
{
   return source;
}

Texture::SourceType Texture::GetSourceType() const
{
   return sourceType;
}
