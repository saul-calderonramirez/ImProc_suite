#include "imageimpro_opencvimpl.h"

ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(){
    this->ptrImage = NULL;
}

ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(char* ptrName){
    this->ptrImage = cvLoadImage(ptrName);
}

ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(ImSize size, int depth, int channels){
    CvSize cvSize;
    cvSize.height = size.height;
    cvSize.width = size.width;
    this->ptrImage = cvCreateImage(cvSize, depth, channels);
}

void ImageImPro_OpenCvImpl::loadImage(char* ptrName){
    this->ptrImage = cvLoadImage(ptrName);
}

void ImageImPro_OpenCvImpl::createImage(ImSize size, int depth, int channels){
    CvSize cvSize;
    cvSize.height = size.height;
    cvSize.width = size.width;
    this->ptrImage = cvCreateImage(cvSize, depth, channels);
}

ImSize ImageImPro_OpenCvImpl::getSize(){
    ImSize size;
    size.height = 0;
    size.width = 0;
    if(this->ptrImage != NULL){
        CvSize cv = cvGetSize(this->ptrImage);
        size.height = cv.height;
        size.width = cv.width;
    }
    return size;
}

IplImage* ImageImPro_OpenCvImpl:: getOpenCvImage(){
    return this->ptrImage;
}

ImageImPro_OpenCvImpl::~ImageImPro_OpenCvImpl(){
    if(this->ptrImage != NULL){
        cvReleaseImage(&this->ptrImage);
    }
}

QImage* ImageImPro_OpenCvImpl::getQImage(){
    QImage* ptrImg = NULL;

    int height = this->ptrImage->height;
    int width = this->ptrImage->width;
    const uchar *qImageBuffer =(const uchar*)this->ptrImage->imageData;
    //RGB 24 bit (8-8-8) image case
    if(this->ptrImage->nChannels == 3 && this->ptrImage->depth == IPL_DEPTH_8U){
        cout << "ENTRO!!" << IPL_DEPTH_8U<< endl;
        ptrImg = new QImage(qImageBuffer, width, height, QImage::Format_RGB888);
        ptrImg = new QImage(ptrImg->rgbSwapped());
    }
    if(this->ptrImage->nChannels == 1 && this->ptrImage->depth == IPL_DEPTH_8U){
        cout << "ENTRO una capa!!" << IPL_DEPTH_8U<< endl;
        ptrImg = new QImage(qImageBuffer, width, height, QImage::Format_Indexed8);
    }
    return ptrImg;
}

