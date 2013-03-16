#include "controller.h"

Controller::Controller(){
}

QImage* Controller::runTest1(){
    this->ptrImage = new ImageImPro_OpenCvImpl("baboon.jpg");
    this->ptrLib = new OpenImProLib_OpenCvImpl();
    ImageImPro* ptrImageCanny = new ImageImPro_OpenCvImpl(this->ptrImage->getSize(), IPL_DEPTH_8U, 1);
    this->ptrLib->filterCanny(ptrImage, ptrImageCanny, 10, 500, 3);
    QImage* qImage = ptrImageCanny->getQImage();
    cout << "Controller test passed" << endl;
    return qImage;

}
Controller::~Controller(){
    delete this->ptrImage;
    delete this->ptrLib;
}





