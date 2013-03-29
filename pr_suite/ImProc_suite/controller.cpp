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
        ImageImPro* ptrImageCanny = new ImageImPro_OpenCvImpl(this->ptrImage->getSize(), ImageImPro::BIT_8_U, 1);
        this->ptrLib->filterCanny(ptrImage, ptrImageCanny, 10, 500, 3);
        delete this->ptrImage;
        ptrImage = ptrImageCanny;    
    }
    else{
         throw ControllerException("No image loaded");
    }
 }

void Controller::applyFilterSobel()throw (ControllerException){
     if(this->ptrImage != NULL){         
         ImageImPro* ptrImageSobel = new ImageImPro_OpenCvImpl(this->ptrImage->getSize(), ImageImPro::BIT_8_U, 1);
         this->ptrLib->filterSobel(ptrImage, ptrImageSobel, 1, 1, 3);         
         delete this->ptrImage;
         ptrImage = ptrImageSobel;
     }
     else{
         throw ControllerException("No image loaded");
     }
 }

void Controller::applyBinaryThreshold()throw (ControllerException){
     if(this->ptrImage != NULL){
         ImageImPro* ptrImageBin = new ImageImPro_OpenCvImpl(this->ptrImage->getSize(), ImageImPro::BIT_8_U, 1);
         this->ptrLib->applyThreshold(this->ptrImage, ptrImageBin, 100, 255, OpenImProLib::BINARY_THRESH);
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
    delete this->ptrImage;
    delete this->ptrLib;
}





