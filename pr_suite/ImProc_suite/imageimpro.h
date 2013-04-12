#ifndef IMAGE_IMPRO_H
#define IMAGE_IMPRO_H
#include "includes.h"
using namespace::cv;
using namespace::std;



typedef struct ImSize{
    int width;
    int height;
}
ImSize;

class ImageImPro{
    public:
        enum ImageImProDepth { BIT_8_U, BIT_16_S, BIT_32_F };
        ImageImPro();
        virtual void loadImage(char* ptrName)=0;
        virtual void createImage(ImSize size, ImageImProDepth depth, int channels)=0;
        virtual ImageImPro* getGrayScale() = 0;
        virtual QImage* getQImage() = 0;
        virtual Mat* getMat() = 0;
        virtual ImSize getSize() = 0;
        virtual IplImage* getOpenCvImage() = 0;
        virtual ~ImageImPro(){}
        virtual ImageImProDepth getDepth() = 0;
        virtual int getChannels() = 0;

};
#endif // IMAGE_IMPRO_H
