#ifndef IMAGEIMPRO_OPENCVIMPL_H
#define IMAGEIMPRO_OPENCVIMPL_H
#include "imageimpro.h"
#include "includes.h"
using namespace cv;


class ImageImPro_OpenCvImpl : public ImageImPro {

private:
    IplImage* ptrImage;
    int depthImPro2Cv(ImageImProDepth depth);
    ImageImProDepth depthCv2ImPro(int depth);
    ImageImProDepth depthMat2ImPro(int depth);
    void cloneImProImage(ImageImPro* ptrImageImPro);
public:
    ImageImPro_OpenCvImpl();
    ImageImPro_OpenCvImpl(Mat* ptrMat);
    ImageImPro_OpenCvImpl(IplImage* ptrImage);
    ImageImPro_OpenCvImpl(GpuMat* ptrMat);
    ImageImPro_OpenCvImpl(ImageImPro* ptrImageImPro);
    ImageImPro_OpenCvImpl(char* ptrName);
    ImageImPro_OpenCvImpl(ImSize size, ImageImProDepth depth, int channels);
    QImage* getQImage();
    Mat* getMat();
    GpuMat* getGPUMat();
    IplImage* getOpenCvImage();
    ImageImPro* getGrayScale();

    void loadImage(char* ptrName);
    void createImage(ImSize size, ImageImProDepth depth, int channels);

    ImSize getSize();    
    ImageImProDepth getDepth();
    int getChannels();
    ~ImageImPro_OpenCvImpl();

};

#endif // IMAGEIMPRO_OPENCVIMPL_H
