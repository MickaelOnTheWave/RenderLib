#ifndef IMAGEDATA_H
#define IMAGEDATA_H

struct ImageData
{
   unsigned int width;
   unsigned int height;
   unsigned int channels;
   unsigned char* data;
};

#endif // IMAGEDATA_H
