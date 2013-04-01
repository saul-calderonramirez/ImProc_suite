#include "controller.h"

Controller::Controller(){
     this->ptrImage = NULL;
     this->ptrLib = new OpenImProLib_OpenCvImpl();
}

void Controller::loadImage(char* ptrName)throw (ControllerException){
    this->ptrImage = new ImageImPro_OpenCvImpl(ptrName);
    if(this->ptrImage == NULL){
        throw ControllerException("Invalid image name");
    }

}

void Controller::applyFilterCanny()throw (ControllerException){
    if(this->ptrImage != NULL){
        ImageImPro* ptrImageCanny = this->ptrLib->filterCanny(ptrImage, 10, 500, 3);
        delete this->ptrImage;
        ptrImage = ptrImageCanny;
    }
    else{
         throw ControllerException("No image loaded");
    }
 }

 void Controller::findCountour()throw (ControllerException){
     if(this->ptrImage != NULL){
         ImageImPro* ptrImageGray = this->ptrLib->convert2GrayScale(this->ptrImage);
     }
     else{
          throw ControllerException("No image loaded");
     }
 }

void Controller::applyFilterSobel()throw (ControllerException){
     if(this->ptrImage != NULL){         

         ImageImPro* ptrImageSobel = this->ptrLib->filterSobel(ptrImage, 1, 1, 3);
         delete this->ptrImage;
         ptrImage = ptrImageSobel;
     }
     else{
         throw ControllerException("No image loaded");
     }
 }

void Controller::applyBinaryThreshold()throw (ControllerException){
     if(this->ptrImage != NULL){

         ImageImPro* ptrImageBin = this->ptrLib->applyThreshold(this->ptrImage, 100, 255, OpenImProLib::BINARY_THRESH);
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





