#include "controller.h"
using namespace std;
Controller::Controller(){
     this->ptrImage = NULL;
     this->ptrLib = new OpenImProLib_OpenCvImpl();
     this->ptrLibGPU = new OpenImProLib_OpenCVGPUimpl();
}

void showImageOnWindow(IplImage* ptrCvImage, char* ptrWinName){
    //Displaying image on opencv window
     //First, the windows name will be set. In this case the window's name is
     //the same as the image name.
     cvNamedWindow(ptrWinName, 1);
     //Second, the image will be displayed
     cvShowImage(ptrWinName, ptrCvImage);
     //Finally, the window will be destroyed right after you press any key
     cvWaitKey();
     cvDestroyWindow(ptrWinName);
}

void Controller::loadImage(char* ptrName)throw (ControllerException){
    this->ptrImage = new ImageImPro_OpenCvImpl(ptrName);
    if(this->ptrImage == NULL){
        throw ControllerException("Invalid image name");
    }

}

void Controller::applyFilterCanny()throw (ControllerException){
    if(this->ptrImage != NULL){
        ImageImPro* ptrImageCanny = this->ptrLibGPU->filterCanny(this->ptrImage, 10, 500, 3);
        delete this->ptrImage;
        ptrImage = ptrImageCanny;
    }
    else{
         throw ControllerException("No image loaded");
    }
 }

void Controller::detectPeople()throw (ControllerException){
    if(this->ptrImage != NULL){
        ImageImPro* ptrOutput = hogGPU.detectPeople(this->ptrImage);
        delete this->ptrImage;
        ptrImage = ptrOutput;
    }
    else{
         throw ControllerException("No image loaded");
    }
}

void Controller::processVideo(){
    char* ptrSrc = "pruebas/REAL1.mp4";
    char* ptrDst = "pruebas/salidaHog.avi";
    hogGPU.processVideo(ptrSrc, ptrDst);
}

void Controller::runBenchmarks()throw (ControllerException){
    if(this->ptrImage != NULL){
        UnitTests::testBenchmarks1(this->ptrImage);
    }
    else{
         throw ControllerException("No image loaded");
    }
}

 void Controller::findCountour()throw (ControllerException){
     if(this->ptrImage != NULL){
        UnitTests::testContours(this->ptrImage);

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
    if(this->ptrLibGPU != NULL)
        delete this->ptrLib;
}
