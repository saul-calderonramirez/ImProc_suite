#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <exception>
#include "openimprolib_opencvimpl.h"
#include "imageimpro_opencvimpl.h"
#define DEF_IMAGE "baboon.jpg"

class Controller{

private:   
    OpenImProLib* ptrLib;
    ImageImPro* ptrImage;

public:   
    class ControllerException: public exception
    {
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
    void loadDefaultImage()throw (ControllerException);
    void applyFilterCanny()throw (ControllerException);
    void applyBinaryThreshold()throw (ControllerException);
    void applyFilterSobel()throw (ControllerException);
    ~Controller();
};

#endif // CONTROLLER_H