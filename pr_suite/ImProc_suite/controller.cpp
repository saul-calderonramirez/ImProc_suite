#include "controller.h"
using namespace std;
Controller::Controller(){
     this->ptrImage = NULL;
     this->ptrLib = new OpenImProLib_OpenCvImpl();
    this->ptrLibGPU = new OpenImProLib_OpenCVGPUimpl();
}

void Controller::loadImage(char* ptrName)throw (ControllerException){
    this->ptrImage = new ImageImPro_OpenCvImpl(ptrName);
    if(this->ptrImage == NULL){
        throw ControllerException("Invalid image name");
    }

}

void Controller::applyFilterCanny()throw (ControllerException){
    if(this->ptrImage != NULL){
        ImageImPro* ptrImageCanny = this->ptrLibGPU->filterCanny(ptrImage, 10, 500, 3);
        delete this->ptrImage;
        ptrImage = ptrImageCanny;
    }
    else{
         throw ControllerException("No image loaded");
    }
 }

void Controller::runBenchmarks()throw (ControllerException){
    if(this->ptrImage != NULL){
        cout << "NEW TEST:" << endl << endl;

        int startMilli, endMilli;
        startMilli = UnitTestsOCV::getMilliCount();
        ImageImPro* ptrOutput = this->ptrLibGPU->filterCanny(ptrImage, 10, 500, 3);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "GPU canny time ms: " << endMilli << endl;
        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLib->filterCanny(ptrImage, 10, 500, 3);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "TBB canny time ms: " << endMilli << endl;

        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLib->applyThreshold(this->ptrImage, 100, 255, OpenImProLib::BINARY_THRESH);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "TBB threshold time ms: " << endMilli << endl;

        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLibGPU->applyThreshold(this->ptrImage, 100, 255, OpenImProLib::BINARY_THRESH);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "GPU threshold time ms: " << endMilli << endl;


        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLibGPU->filterSobel(ptrImage, 1, 1, 3);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "GPU sobel time ms: " << endMilli << endl;

        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLib->filterSobel(ptrImage, 1, 1, 3);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "TBB sobel time ms: " << endMilli << endl;


        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLibGPU->filterGauss(this->ptrImage, 0, 0, 11);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "GPU gauss time ms: " << endMilli << endl;


        startMilli = UnitTestsOCV::getMilliCount();
        ptrOutput = this->ptrLib->filterGauss(this->ptrImage, 0, 0, 11);
        delete ptrOutput;
        endMilli = UnitTestsOCV::getMilliSpan(startMilli);
        cout << "TBB gauss time ms: " << endMilli << endl;







    }
    else{
         throw ControllerException("No image loaded");
    }
}

 void Controller::findCountour()throw (ControllerException){
     if(this->ptrImage != NULL){
         ImageImPro* ptrImageCanny =  this->ptrLib->applyThreshold(this->ptrImage, 100, 255, OpenImProLib::BINARY_THRESH);
         ImageImPro* ptrGrayRes = this->ptrImage->getGrayScale();
         IplImage* ptrGrayCv =  ptrGrayRes->getOpenCvImage();
         cvZero(ptrGrayCv);
         CvMemStorage* ptrMemStorage = cvCreateMemStorage(0);
         CvSeq* ptrContours = 0;
         IplImage* ptrIm = ptrImageCanny->getOpenCvImage();
         cvFindContours(ptrIm, ptrMemStorage, &ptrContours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
         if(ptrContours != NULL){
             cvDrawContours(ptrGrayCv, ptrContours, cvScalarAll(255), cvScalarAll(255), 100 );
             cvShowImage("Contours", ptrGrayCv);
         }

     }
     else{
          throw ControllerException("No image loaded");
     }
 }

void Controller::applyFilterSobel()throw (ControllerException){
     if(this->ptrImage != NULL){         
         ImageImPro* ptrImageSobel = this->ptrLibGPU->filterSobel(ptrImage, 1, 1, 3);
         delete this->ptrImage;
         ptrImage = ptrImageSobel;
     }
     else{
         throw ControllerException("No image loaded");
     }
 }

void Controller::applyFilterGauss()throw (ControllerException){
    if(this->ptrImage != NULL){
        ImageImPro* ptrImageGauss = this->ptrLibGPU->filterGauss(this->ptrImage, 0, 0, 11);
        delete this->ptrImage;
        ptrImage = ptrImageGauss;
    }
    else{
        throw ControllerException("No image loaded");
    }

}

void Controller::applyBinaryThreshold()throw (ControllerException){
     if(this->ptrImage != NULL){
         //ImageImPro* ptrImageBin = this->ptrLib->applyThreshold(this->ptrImage, 100, 255, OpenImProLib::BINARY_THRESH);
         ImageImPro* ptrImageBin = this->ptrLibGPU->applyThreshold(this->ptrImage, 100, 255, OpenImProLib::BINARY_THRESH);
         delete this->ptrImage;
         ptrImage = ptrImageBin;
     }
     else{
         throw ControllerException("No image loaded");
     }
 }

 ImageImPro* Controller::getImage(){
    return this->ptrImage;
 }


Controller::~Controller(){
    if(this->ptrImage != NULL)
        delete this->ptrImage;
    if(this->ptrLib != NULL)
        delete this->ptrLib;
}





