#include "openimprolib_opencvimpl.h"


OpenImProLib_OpenCvImpl::OpenImProLib_OpenCvImpl(){


}

ImageImPro* OpenImProLib_OpenCvImpl::filterCanny(ImageImPro* ptrInput, double limInf, double limSup, int apertureSize){
    ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrInput->getSize(), ImageImPro::BIT_8_U, 1);
    IplImage* ptrInputCv = ptrInput->getOpenCvImage();
    IplImage* ptrOutputCv = ptrOutput->getOpenCvImage();
    cvCanny(ptrInputCv, ptrOutputCv, limInf, limSup, apertureSize);
    return ptrOutput;
}

int OpenImProLib_OpenCvImpl::imProThresh2CvThresh(ThresholdType thresholdType){
    int cvThreshType = -1;
    switch(thresholdType){
           case BINARY_THRESH:
                cvThreshType = CV_THRESH_BINARY;
           break;
           case BINARY_INV_THRESH:
                cvThreshType = CV_THRESH_BINARY_INV;
           break;
           case TRUNC_THRESH:
                cvThreshType = CV_THRESH_TRUNC;
           break;
           case TO_ZERO_THRESH:
                cvThreshType = CV_THRESH_TOZERO;
           break;
           case TO_ZERO_INV_THRESH:
                cvThreshType = CV_THRESH_TOZERO_INV;
           break;
    }
    return cvThreshType;

}

ImageImPro* OpenImProLib_OpenCvImpl::applyThreshold(ImageImPro* ptrInput, double threshold, double maxValue, ThresholdType typeThresh){
     ImageImPro* ptrOutput =new ImageImPro_OpenCvImpl(ptrInput->getSize(), ImageImPro::BIT_8_U, 1);
     IplImage* ptrCvInput = ptrInput->getOpenCvImage();
     IplImage* ptrCvOutput = ptrOutput->getOpenCvImage();
     int cvThresholdType = imProThresh2CvThresh(typeThresh);
     if(ptrInput->getChannels() != 1){
         IplImage* ptrCvInputGray = cvCreateImage(cvSize(ptrCvInput->width,ptrCvInput->height),IPL_DEPTH_8U,1);
         cvCvtColor(ptrCvInput,ptrCvInputGray, CV_RGB2GRAY);
         cvThreshold(ptrCvInputGray, ptrCvOutput, threshold, maxValue, cvThresholdType);
         cvReleaseImage(&ptrCvInputGray);
     }
     else{
        cvThreshold(ptrCvInput, ptrCvOutput, threshold, maxValue, cvThresholdType);
     }
     ptrOutput = new ImageImPro_OpenCvImpl(ptrCvOutput);
     return ptrOutput;
}



ImageImPro* OpenImProLib_OpenCvImpl::filterSobel(ImageImPro* ptrInput, int xOrder, int yOrder, int apertureSize){
    ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrInput->getSize(), ImageImPro::BIT_8_U, 1);
    IplImage* ptrCvInput = ptrInput->getOpenCvImage();
    //buffer for sobel result needing more bits per pixel for the result, then, rescaling is necesary to get it back to 8 bits per pixel
    IplImage* ptrCvTemp = cvCreateImage(cvGetSize(ptrCvInput),IPL_DEPTH_32F,1);
    IplImage* ptrCvOutput = ptrOutput->getOpenCvImage();
    if(ptrInput->getChannels() != 1){
        IplImage* ptrCvInputGray = cvCreateImage(cvSize(ptrCvInput->width,ptrCvInput->height),IPL_DEPTH_8U,1);
        cvCvtColor(ptrCvInput,ptrCvInputGray, CV_RGB2GRAY);
        cvSobel(ptrCvInputGray,ptrCvTemp, xOrder, yOrder, apertureSize);
        cvReleaseImage(&ptrCvInputGray);
    }
    else{
        cvSobel(ptrCvInput,ptrCvTemp, xOrder, yOrder, apertureSize);
    }
    cvConvertScale(ptrCvTemp, ptrCvOutput, 1, 0);
    /*
    cvNamedWindow("sobel");
    cvShowImage("sobel", ptrCvTemp);
    */
    cvReleaseImage(&ptrCvTemp);
    return ptrOutput;
}
