#ifndef IMAGE_IMPRO_H
#define IMAGE_IMPRO_H
#include "highgui.h"
#include "cv.h"
#include <QMainWindow>
#include <iostream>
using namespace::std;



typedef struct ImSize{
    int width;
    int height;
}
ImSize;

class ImageImPro{
    public:
        enum ImageImProDepth { BIT_8_U, BIT_16_S, BIT_32_F, INVALID };
        ImageImPro();
        virtual void loadImage(char* ptrName)=0;
        virtual void createImage(ImSize size, ImageImProDepth depth, int channels)=0;
        virtual QImage* getQImage() = 0;
        virtual ImSize getSize() = 0;
        virtual IplImage* getOpenCvImage() = 0;
        virtual ~ImageImPro(){}
        virtual ImageImProDepth getDepth() = 0;
        virtual int getChannels() = 0;

};
#endif // IMAGE_IMPRO_H
