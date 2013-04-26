#include "imageimpro_opencvimpl.h"

ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(){
    this->ptrImage = NULL;
}

ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(char* ptrName){
      loadImage(ptrName);
}

ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(ImSize size, ImageImProDepth depth, int channels){
     createImage(size, depth, channels);
}


 ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(IplImage* ptrInput){
     ImSize size;
     ImageImProDepth depth = depthCv2ImPro(ptrInput->depth);
     size.height = ptrInput->height;
     size.width = ptrInput->width;
     int channels = ptrInput->nChannels;
     //creates the image and asks for memory
     createImage(size, depth, channels);
     //copies the memory
     memcpy(this->ptrImage->imageData, ptrInput->imageData, size.height * ptrInput->widthStep);
 }

  ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(GpuMat* ptrGpuMat){
    //Buffer Matrix necessary
    Mat* ptrMat = new Mat(*ptrGpuMat);
    ImSize size;
    ImageImProDepth depth = depthMat2ImPro(ptrMat->depth());
    size.height = ptrMat->rows;
    size.width = ptrMat->cols;
    int channels = ptrMat->channels();
    //creates the image and asks for memory
    createImage(size, depth, channels);
    //copies the memory
    IplImage iplTemp = *ptrMat;
    memcpy(this->ptrImage->imageData, iplTemp.imageData, iplTemp.widthStep * iplTemp.height);
    delete ptrMat;
  }



 ImageImPro_OpenCvImpl::ImageImPro_OpenCvImpl(Mat* ptrMat){
     ImSize size;
     ImageImProDepth depth = depthMat2ImPro(ptrMat->depth());
     size.height = ptrMat->rows;
     size.width = ptrMat->cols;
     int channels = ptrMat->channels();
     //creates the image and asks for memory
     createImage(size, depth, channels);
     //copies the memory
     IplImage iplTemp = *ptrMat;
     memcpy(this->ptrImage->imageData, iplTemp.imageData, iplTemp.widthStep * iplTemp.height);

 }



ImageImPro::ImageImProDepth ImageImPro_OpenCvImpl::getDepth(){
    int depthCv = IPL_DEPTH_8U;
    ImageImProDepth depthImPro = ImageImPro::BIT_8_U;
    if(this->ptrImage != NULL){
        depthCv = this->ptrImage->depth;
        if(depthCv == IPL_DEPTH_32F){
            depthImPro = ImageImPro::BIT_32_F;
        }
    }   
    return depthImPro;

}

int ImageImPro_OpenCvImpl::getChannels(){
    int channels = 0;
    if(this->ptrImage != NULL){
        channels = this->ptrImage->nChannels;
    }
    return channels;
}

void ImageImPro_OpenCvImpl::loadImage(char* ptrName){
    this->ptrImage = cvLoadImage(ptrName);

}

int ImageImPro_OpenCvImpl::depthImPro2Cv(ImageImPro::ImageImProDepth depth){
    int depthCv = 0;
    switch(depth){
        case ImageImPro::BIT_8_U:
            depthCv = IPL_DEPTH_8U;
        break;
        case ImageImPro::BIT_16_S:
            depthCv = IPL_DEPTH_16S;
        break;
        case ImageImPro::BIT_32_F:
            depthCv = IPL_DEPTH_32F;
        break;

    }
    return depthCv;
}

ImageImPro_OpenCvImpl::ImageImProDepth ImageImPro_OpenCvImpl::depthCv2ImPro(int depth){
    ImageImProDepth depthImPro;
    switch(depth){
        case IPL_DEPTH_8U:
            depthImPro = ImageImPro_OpenCvImpl::BIT_8_U;
        break;
        case IPL_DEPTH_16S:
            depthImPro = ImageImPro_OpenCvImpl::BIT_16_S;
        break;
        case IPL_DEPTH_32F:
            depthImPro = ImageImPro_OpenCvImpl::BIT_32_F;
        break;
    }
    return depthImPro;
}

ImageImPro_OpenCvImpl::ImageImProDepth ImageImPro_OpenCvImpl::depthMat2ImPro(int depth){
    ImageImProDepth depthImPro;
    switch(depth){
        case CV_8U:
            depthImPro = ImageImPro_OpenCvImpl::BIT_8_U;
        break;
        case CV_16S:
            depthImPro = ImageImPro_OpenCvImpl::BIT_16_S;
        break;
        case CV_32F:
            depthImPro = ImageImPro_OpenCvImpl::BIT_32_F;
        break;
    }
    return depthImPro;
}

void ImageImPro_OpenCvImpl::createImage(ImSize size, ImageImProDepth depth, int channels){
    int depthCv = depthImPro2Cv(depth);
    CvSize cvSize;
    cvSize.height = size.height;
    cvSize.width = size.width;
    this->ptrImage = cvCreateImage(cvSize, depthCv, channels);
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
    int depthCv = depthImPro2Cv(this->getDepth());
    CvSize cvSize;
    cvSize.height = this->getSize().height;
    cvSize.width = this->getSize().width;
    IplImage* ptrIplImage = cvCreateImage(cvSize, depthCv, this->getChannels());
    memcpy(ptrIplImage->imageData, this->ptrImage->imageData, this->ptrImage->widthStep * cvSize.height);
    return ptrIplImage;
}

 GpuMat* ImageImPro_OpenCvImpl::getGPUMat(){
    Mat* ptrMat = this->getMat();
    GpuMat* ptrGpuMat = new GpuMat();
    ptrGpuMat->upload(*ptrMat);
    return ptrGpuMat;
 }

ImageImPro* ImageImPro_OpenCvImpl::getGrayScale(){
    IplImage *ptrCvImGray = cvCreateImage(cvGetSize(this->ptrImage),IPL_DEPTH_8U,1);
    cvCvtColor(this->ptrImage, ptrCvImGray, CV_RGB2GRAY);
    ImageImPro* ptrImGray = new  ImageImPro_OpenCvImpl(ptrCvImGray);
    return ptrImGray;
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
        ptrImg = new QImage(qImageBuffer, width, height, QImage::Format_RGB888);
        //OpenCv image is GRB, needs to be swapped
        ptrImg = new QImage(ptrImg->rgbSwapped());
    }
    //8 bit, one channel case
    if(this->ptrImage->nChannels == 1 && this->ptrImage->depth == IPL_DEPTH_8U){      
        ptrImg = new QImage(qImageBuffer, width, height, QImage::Format_Indexed8);
    }
    if(this->ptrImage->nChannels == 1 && this->ptrImage->depth == (int)IPL_DEPTH_16S){
        ptrImg = new QImage(qImageBuffer, width, height, QImage::Format_Indexed8);
    }

    return ptrImg;
}

Mat* ImageImPro_OpenCvImpl::getMat(){
    //copies the data
    Mat* ptrMat = new Mat(this->ptrImage, true);    
    return ptrMat;
}

