#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <string>

#include "ImageData.h"
#include "math/Vector3.h"

class ImageLoader
{
public:
   ImageLoader() = delete;

   static ImageData FromFile(const std::string& filename);
   static ImageData FromColor(const Vector3& color);
};

#endif // IMAGELOADER_H
