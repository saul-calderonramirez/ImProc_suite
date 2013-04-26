#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "includes.h"
#include "openimprolib_opencvimpl.h"
#include "imageimpro_opencvimpl.h"
#include "openimprolib_opencvoclimpl.h"
#include "openimprolib_opencvgpuimpl.h"
#include "unittests.h"
#include "hogdetectorgpu.h"
#define DEF_IMAGE "peqFut.bmp"

class Controller{

private:   
    OpenImProLib* ptrLib;
    OpenImProLib* ptrLibGPU;
    ImageImPro* ptrImage;
    HOGDetectorGPU hogGPU;

public:   
    class ControllerException: public exception{
      public:
      const char* ptrMessage;
      ControllerException(){}
      ControllerException(const char* ptrErrorMessage):ptrMessage(ptrErrorMessage){
        this->ptrMessage = ptrMessage;
      }
      virtual const char* what() const throw(){
        return this->ptrMessage;
      }
    }controllerException;
    Controller();
    ImageImPro* getImage();
    void loadImage(char* ptrName)throw (ControllerException);
    void applyFilterCanny()throw (ControllerException);
    void applyBinaryThreshold()throw (ControllerException);
    void applyFilterSobel()throw (ControllerException);
    void applyFilterGauss()throw (ControllerException);
    void detectPeople()throw (ControllerException);
    void processVideo();
    void findCountour()throw (ControllerException);
    void runBenchmarks()throw (ControllerException);
    ~Controller();
};

#endif // CONTROLLER_H
