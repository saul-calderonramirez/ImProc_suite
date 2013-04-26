#include "openimprolib_opencvimpl.h"


OpenImProLib_OpenCvImpl::OpenImProLib_OpenCvImpl(){


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

ImageImPro* OpenImProLib_OpenCvImpl::filterCanny(ImageImPro* ptrInput, double limInf, double limSup, int apertureSize){    
    IplImage* ptrInputCv = ptrInput->getOpenCvImage();
    IplImage* ptrOutputCv = cvCreateImage(cvGetSize(ptrInputCv), IPL_DEPTH_8U, 1);
    cvCanny(ptrInputCv, ptrOutputCv, limInf, limSup, apertureSize);
    ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrOutputCv);    
    cvReleaseImage(&ptrOutputCv);
    cvReleaseImage(&ptrInputCv);
    return ptrOutput;
}

ImageImPro* OpenImProLib_OpenCvImpl::filterGauss(ImageImPro* ptrInput, double sigmaX, double sigmaY, int apertureSize){    
    Size size;
    size.width = apertureSize;
    size.height = apertureSize;
    Mat* ptrMatOutput = new Mat();
    Mat* ptrMatInput = ptrInput->getMat();
    GaussianBlur(*ptrMatInput, *ptrMatOutput, size, sigmaX, sigmaY);
    ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);
    delete ptrMatOutput;
    delete ptrMatInput;
    return ptrOutput;
}

ImageImPro* OpenImProLib_OpenCvImpl::applyThreshold(ImageImPro* ptrInput, double threshold, double maxValue, ThresholdType typeThresh){     
     IplImage* ptrCvInput = ptrInput->getOpenCvImage();
     IplImage* ptrCvOutput = cvCreateImage(cvGetSize(ptrCvInput), IPL_DEPTH_8U, 1);
     int cvThresholdType = imProThresh2CvThresh(typeThresh);
     if(ptrInput->getChannels() != 1){
         IplImage* ptrCvInputGray = cvCreateImage(cvSize(ptrCvInput->width, ptrCvInput->height),IPL_DEPTH_8U,1);
         cvCvtColor(ptrCvInput,ptrCvInputGray, CV_RGB2GRAY);
         cvThreshold(ptrCvInputGray, ptrCvOutput, threshold, maxValue, cvThresholdType);
         cvReleaseImage(&ptrCvInputGray);
     }
     else{
        cvThreshold(ptrCvInput, ptrCvOutput, threshold, maxValue, cvThresholdType);
     }
     ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrCvOutput);
     cvReleaseImage(&ptrCvOutput);
     cvReleaseImage(&ptrCvInput);
     return ptrOutput;
}



ImageImPro* OpenImProLib_OpenCvImpl::filterSobel(ImageImPro* ptrInput, int xOrder, int yOrder, int apertureSize){  
    IplImage* ptrCvInput = ptrInput->getOpenCvImage();
    //buffer for sobel result needing more bits per pixel for the result, then, rescaling is necesary to get it back to 8 bits per pixel
    IplImage* ptrCvTemp = cvCreateImage(cvGetSize(ptrCvInput),IPL_DEPTH_32F,1);
    IplImage* ptrCvOutput = cvCreateImage(cvGetSize(ptrCvInput), IPL_DEPTH_8U, 1);
    if(ptrInput->getChannels() != 1){
        IplImage* ptrCvInputGray = cvCreateImage(cvSize(ptrCvInput->width,ptrCvInput->height),IPL_DEPTH_8U,1);
        cvCvtColor(ptrCvInput,ptrCvInputGray, CV_RGB2GRAY);
        cvSobel(ptrCvInputGray,ptrCvTemp, xOrder, yOrder, apertureSize);
        cvReleaseImage(&ptrCvInputGray);
    }
    else{
        cvSobel(ptrCvInput,ptrCvTemp, xOrder, yOrder, apertureSize);
    }
    cvConvertScaleAbs(ptrCvTemp, ptrCvOutput, 1, 0);
    ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrCvOutput);
    cvReleaseImage(&ptrCvOutput);
    cvReleaseImage(&ptrCvInput);
    cvReleaseImage(&ptrCvTemp);
    return ptrOutput;
}
