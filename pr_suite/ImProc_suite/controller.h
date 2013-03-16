#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "openimprolib_opencvimpl.h"
#include "imageimpro_opencvimpl.h"

class Controller{

private:
    //Choose the OpenImProLib implementation
    OpenImProLib* ptrLib;
    ImageImPro* ptrImage;

public:
    Controller();
    QImage* runTest1();
    ~Controller();
};

#endif // CONTROLLER_H
