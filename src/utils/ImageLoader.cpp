#include "ImageLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


ImageData ImageLoader::FromFile(const std::string& filename)
{
   const int colorChannels = 3; // TODO find a way to get real data
   ImageData image;
   int width = 0, height = 0, channels = 0;
   image.data = stbi_load(filename.c_str(), &width, &height, &channels, colorChannels);
   image.width = static_cast<unsigned int>(width);
   image.height = static_cast<unsigned int>(height);
   image.channels = static_cast<unsigned int>(channels);
   return image;
}

ImageData ImageLoader::FromColor(const Vector3& color)
{
   ImageData image;
   image.width = 2;
   image.height = 2;
   image.channels = 3;
   auto textureData = new unsigned char[image.width * image.height * image.channels];
   for (unsigned int i=0; i<image.width * image.height; ++i)
   {
      const unsigned int pixelIndex = i * image.channels;
      textureData[pixelIndex] = color.X();
      textureData[pixelIndex+1] = color.Y();
      textureData[pixelIndex+2] = color.Z();
   }

   return image;
}
