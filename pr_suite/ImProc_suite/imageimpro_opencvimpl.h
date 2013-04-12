#ifndef IMAGEIMPRO_OPENCVIMPL_H
#define IMAGEIMPRO_OPENCVIMPL_H
#include "imageimpro.h"
#include "includes.h"
using namespace cv;


class ImageImPro_OpenCvImpl : public ImageImPro {

private:
    IplImage* ptrImage;
    int depthImPro2Cv(ImageImPro::ImageImProDepth depth);
    ImageImProDepth depthMat2ImPro(int depth);

public:
    ImageImPro_OpenCvImpl();
    ImageImPro_OpenCvImpl(Mat* ptrMat);
    ImageImPro_OpenCvImpl(IplImage* ptrImage);
    ImageImPro_OpenCvImpl(char* ptrName);
    ImageImPro_OpenCvImpl(ImSize size, ImageImProDepth depth, int channels);
    QImage* getQImage();
    Mat* getMat();
    ImageImPro* getGrayScale();
    void loadImage(char* ptrName);
    void createImage(ImSize size, ImageImProDepth depth, int channels);    
    ImSize getSize();
    IplImage* getOpenCvImage();
    ImageImProDepth getDepth();
    int getChannels();
    ~ImageImPro_OpenCvImpl();

};

#endif // IMAGEIMPRO_OPENCVIMPL_H
