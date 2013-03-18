#include "openimprolib_opencvimpl.h"
#include <iostream>
using namespace std;

OpenImProLib_OpenCvImpl::OpenImProLib_OpenCvImpl(){


}

void OpenImProLib_OpenCvImpl::filterCanny(ImageImPro* ptrInput, ImageImPro* ptrOutput, double limInf, double limSup, int apertureSize){
    IplImage* ptrInputCv = ptrInput->getOpenCvImage();
    IplImage* ptrOutputCv = ptrOutput->getOpenCvImage();
    cvCanny(ptrInputCv, ptrOutputCv, limInf, limSup, apertureSize);
}

 ImageImPro* OpenImProLib_OpenCvImpl::convert2GrayScale(ImageImPro* ptrImage){
     IplImage* ptrCvImage = ptrImage->getOpenCvImage();
     IplImage *ptrCvImGray = cvCreateImage(cvGetSize(ptrCvImage),IPL_DEPTH_8U,1);
     cvCvtColor(ptrImage, ptrCvImGray, CV_RGB2GRAY);
     ImageImPro* ptrImGray = new  ImageImPro_OpenCvImpl(ptrCvImGray);
     return ptrImGray;
 }

void OpenImProLib_OpenCvImpl::filterSobel(ImageImPro* ptrInput, ImageImPro* ptrOutput, int xOrder, int yOrder, int apertureSize){
    /*ImageImPro* ptrImGray = convert2GrayScale(ptrInput);
    IplImage* ptrOutputCv = ptrOutput->getOpenCvImage();
    cvSobel(ptrImGray->getOpenCvImage(), ptrOutputCv, xOrder, yOrder, apertureSize);
    Sobel( ptrImGray->getOpenCvImage(), grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    cout << "va aqui" << endl;*/

    IplImage* src = ptrInput->getOpenCvImage();
    IplImage* sobel = cvCreateImage(cvSize(src->width,src->height),IPL_DEPTH_8U,1);
    IplImage* dst = ptrOutput->getOpenCvImage();
    IplImage* finalResult = cvCreateImage(cvSize(src->width,src->height),IPL_DEPTH_8U,1);

    cvCvtColor(src,sobel, CV_RGB2GRAY);
    cvSobel(sobel,dst, xOrder, yOrder, apertureSize);
    cvConvertScale(dst, finalResult, 1, 0);
   // delete ptrOutput;
    //ptrOutput = new ImageImPro_OpenCvImpl(finalResult);

    cvNamedWindow("sobel");
    cvShowImage("sobel", finalResult);
}
