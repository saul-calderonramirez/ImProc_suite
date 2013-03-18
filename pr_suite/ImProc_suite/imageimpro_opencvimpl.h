#ifndef IMAGEIMPRO_OPENCVIMPL_H
#define IMAGEIMPRO_OPENCVIMPL_H
#include "imageimpro.h"


class ImageImPro_OpenCvImpl : public ImageImPro {

private:
    IplImage* ptrImage;
    int depthImPro2Cv(ImageImPro::ImageImProDepth depth);

public:
    ImageImPro_OpenCvImpl();
    ImageImPro_OpenCvImpl(IplImage* ptrImage);
    ImageImPro_OpenCvImpl(char* ptrName);
    ImageImPro_OpenCvImpl(ImSize size, ImageImProDepth depth, int channels);
    QImage* getQImage();
    void loadImage(char* ptrName);
    void createImage(ImSize size, ImageImProDepth depth, int channels);    
    ImSize getSize();
    IplImage* getOpenCvImage();
    ImageImProDepth getDepth();
    int getChannels();
    ~ImageImPro_OpenCvImpl();

};

#endif // IMAGEIMPRO_OPENCVIMPL_H
