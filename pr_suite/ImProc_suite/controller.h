#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "openimprolib_opencvimpl.h"
#include "imageimpro_opencvimpl.h"
#define DEF_IMAGE "baboon.jpg"

class Controller{

private:   
    OpenImProLib* ptrLib;
    ImageImPro* ptrImage;

public:
    enum Status{OK, FAIL};
    Controller();
    ImageImPro* getImage();
    Status loadDefaultImage();
    Status applyFilterCanny();
    Status applyFilterSobel();
    ~Controller();
};

#endif // CONTROLLER_H
