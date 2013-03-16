#include "openimprolib_opencvimpl.h"
#include <iostream>
using namespace std;

OpenImProLib_OpenCvImpl::OpenImProLib_OpenCvImpl(){


}

void OpenImProLib_OpenCvImpl:: filterCanny(ImageImPro* ptrInput, ImageImPro* ptrOutput, double limInf, double limSup, double apertureSize){
    IplImage* ptrInputCv = ptrInput->getOpenCvImage();
    IplImage* ptrOutputCv = ptrOutput->getOpenCvImage();
    cvCanny(ptrInputCv, ptrOutputCv, limInf, limSup, apertureSize);
}
