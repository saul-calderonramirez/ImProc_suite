#include "controller.h"
using namespace std;
Controller::Controller(){
     this->ptrImage = NULL;
     this->ptrLib = new OpenImProLib_OpenCvImpl();
     this->ptrLibGPU = new OpenImProLib_OpenCVGPUimpl();
}



void Controller::loadImage(char* ptrName)throw (ControllerException){
    if(this->ptrImage != NULL){
        delete this->ptrImage;
    }
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

vector<float> Controller::detectPeople()throw (ControllerException){
    vector<float> descriptors(1);
    if(this->ptrImage != NULL){
      //  ImageImPro* ptrOutput = hogGPU.detectPeople(this->ptrImage);
       // showImageOnWindow(ptrOutput->getOpenCvImage(), "detect");
        //hogGPU.getDescriptors(this->ptrImage);
     /*   delete this->ptrImage;
        ptrImage = ptrOutput;*/
        descriptors = hogGPU.getHOGdescriptors(this->ptrImage);
        //hogGPU.saveHOGdescriptorsToFile("hogDescriptors.txt", descriptors, 1);
        NeuralNet neuralNet;

        neuralNet.writeDataHeader("trainDescriptors.txt", 40);
        hogGPU.saveHOGdescriptorsFromDir("hog_muestras/training/pos", "trainDescriptors.txt", 1);
        hogGPU.saveHOGdescriptorsFromDir("hog_muestras/training/neg", "trainDescriptors.txt", -1);
        neuralNet.trainNet("trainDescriptors.txt");

        neuralNet.writeDataHeader("testDescriptors.txt", 10);
        hogGPU.saveHOGdescriptorsFromDir("hog_muestras/testing/pos", "testDescriptors.txt", 1);
        hogGPU.saveHOGdescriptorsFromDir("hog_muestras/testing/neg", "testDescriptors.txt", -1);
        neuralNet.runNet("testDescriptors.txt");

    }
    else{
         throw ControllerException("No image loaded");
    }
    return descriptors;
}

void Controller::processVideo(){
    char* ptrSrc = "../../../videos/REAL1.mp4";
    char* ptrDst = "../../../videos/salidaHog.avi";
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
        ImageImPro* ptrTemp = this->ptrLib->thresholdEqualsRGB(this->ptrImage, RGB_VALUE(FUCSIA));
        ptrTemp->showImageOnWindow("AfterThreshEquals");
        ImageImPro** ptrTemp2 = this->ptrLib->getCounturedObjectMask(ptrTemp, this->ptrImage, 253);
        ptrTemp2[0]->showImageOnWindow("AfterGettingObject");
        ptrTemp2[1]->showImageOnWindow("AfterGettingObject");
        delete ptrTemp2[0];
        delete ptrTemp2[1];
        delete ptrTemp;

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
        delete this->ptrLibGPU;
}
