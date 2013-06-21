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
    ImageImPro* getHSV();
    void loadImage(char* ptrName);
    void createImage(ImSize size, ImageImProDepth depth, int channels);

    ImSize getSize();    
    ImageImProDepth getDepth();
    int getChannels();
    ~ImageImPro_OpenCvImpl();

    void setPV(int x, int y, int value, int layer = 0);
    int getPV(int x, int y, int layer = 0);
    RGB_VALUE getPV_RGB(int x, int y);
    QImage* MatToQImage(const Mat& mat);

    void setPV(int x, int y, RGB_VALUE value);
    void showImageOnWindow(char* ptrWinName){
        IplImage* ptrCvImage = getOpenCvImage();
        //Displaying image on opencv window
         //First, the windows name will be set. In this case the window's name is
         //the same as the image name.
         cvNamedWindow(ptrWinName, 1);
         //Second, the image will be displayed
         cvShowImage(ptrWinName, ptrCvImage);
         //Finally, the window will be destroyed right after you press any key
         cvWaitKey();
         cvDestroyWindow(ptrWinName);
         cvReleaseImage(&ptrCvImage);
    }
};

#endif
