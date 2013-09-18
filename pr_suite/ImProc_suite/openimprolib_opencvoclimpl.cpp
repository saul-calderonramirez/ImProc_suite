#include "openimprolib_opencvoclimpl.h"
//Needs OpenCL 1.2 to be running!
OpenImProLib_OpenCVOCLimpl::OpenImProLib_OpenCVOCLimpl(){
    //inits the opencl enviroment
   /* ocl::setBinpath("/usr/lib/x86_64-linux-gnu/");
    vector<ocl::Info> info;
    CV_Assert(ocl::getDevice(info));
    std::cout<<"Init hecho!"<< std::endl;*/
}

ImageImPro* OpenImProLib_OpenCVOCLimpl::filterCanny(ImageImPro* input, double limInf, double limSup, int apertureSize){
   /* ImageImPro* ptrImProGray = input->getGrayScale();
    cout << "Entro filter canny" << endl;
    ocl::setBinpath("/usr/lib/x86_64-linux-gnu/");
    vector<ocl::Info> info;
    CV_Assert(ocl::getDevice(info));
    std::cout<<"Init hecho!"<< std::endl;
    Mat* ptrMatInput = ptrImProGray->getMat();
    namedWindow( "wndname", 1 );
    imshow("wndname", *ptrMatInput);
    int c = waitKey();
    Mat matInput = imread("baboon.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    ocl::oclMat oclMatInput(matInput);
    cout << "construyo oclMatInput" << endl;
    ocl::oclMat oclMatOutput;
    ocl::Canny(oclMatInput, oclMatOutput, limInf, limSup, apertureSize);
    cout << "Hizo canny" << endl;
    Mat* ptrOutputMat = new Mat(oclMatOutput);
    ImageImPro* ptrImproOutput = new ImageImPro_OpenCvImpl(ptrOutputMat);
    delete ptrImProGray;
    delete ptrMatInput;*/
    return NULL;
}
ImageImPro* OpenImProLib_OpenCVOCLimpl::filterSobel(ImageImPro* input, int xOrder, int yOrder, int apertureSize){
    return NULL;
}

ImageImPro* OpenImProLib_OpenCVOCLimpl::filterGauss(ImageImPro*, double, double, int){
    return NULL;
}
ImageImPro* OpenImProLib_OpenCVOCLimpl::applyThreshold(ImageImPro* input, double threshold, double maxValue, ThresholdType typeThresh){
    return NULL;
}

