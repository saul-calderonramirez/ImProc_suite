#include "controller.h"

Controller::Controller(){
     this->ptrImage = NULL;
     this->ptrLib = new OpenImProLib_OpenCvImpl();
}

Controller::Status Controller::loadDefaultImage(){
    Controller::Status status = OK;
    char* name = (char*)DEF_IMAGE;
    this->ptrImage = new ImageImPro_OpenCvImpl(name);
    if(this->ptrImage == NULL){
        status = FAIL;
    }

    return status;
}

 Controller::Status Controller::applyFilterCanny(){
    Controller::Status status = FAIL;
    if(this->ptrImage != NULL){
        ImageImPro* ptrImageCanny = new ImageImPro_OpenCvImpl(this->ptrImage->getSize(), ImageImPro::BIT_8_U, 1);
        this->ptrLib->filterCanny(ptrImage, ptrImageCanny, 10, 500, 3);
        delete this->ptrImage;
        ptrImage = ptrImageCanny;
        status = OK;
    }
    return status;
 }

 Controller::Status Controller::applyFilterSobel(){
     Controller::Status status = FAIL;     
     if(this->ptrImage != NULL){
         //CONVERT TO GRAYSCALE
         //RESULT TO result can be converted back to 8-bit using cvConvertScale or cvConvertScaleAbs functions
         ImageImPro* ptrImageSobel = new ImageImPro_OpenCvImpl(this->ptrImage->getSize(), ImageImPro::BIT_32_F, 1);
         this->ptrLib->filterSobel(ptrImage, ptrImageSobel, 1, 1, 3);
         delete this->ptrImage;
         ptrImage = ptrImageSobel;
         status = OK;
     }
     return status;
 }

 ImageImPro* Controller::getImage(){
    return this->ptrImage;
 }


Controller::~Controller(){
    delete this->ptrImage;
    delete this->ptrLib;
}





