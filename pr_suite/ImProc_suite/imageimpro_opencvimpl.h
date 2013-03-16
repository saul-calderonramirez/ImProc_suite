#ifndef IMAGEIMPRO_OPENCVIMPL_H
#define IMAGEIMPRO_OPENCVIMPL_H
#include "imageimpro.h"


class ImageImPro_OpenCvImpl : public ImageImPro {

private:
    IplImage* ptrImage;

public:
    ImageImPro_OpenCvImpl();
    ImageImPro_OpenCvImpl(char* ptrName);
    ImageImPro_OpenCvImpl(ImSize size, int depth, int channels);
    QImage* getQImage();
    void loadImage(char* ptrName);
    void createImage(ImSize size, int depth, int channels);
    ImSize getSize();
    IplImage* getOpenCvImage();
    ~ImageImPro_OpenCvImpl();

};

#endif // IMAGEIMPRO_OPENCVIMPL_H
