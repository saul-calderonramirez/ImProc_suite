#ifndef HOGDETECTORGPU_H
#define HOGDETECTORGPU_H
#include "imageimpro_opencvimpl.h"
class HOGDetectorGPU{

public:
    HOGDetectorGPU();
    ImageImPro* detectPeople(ImageImPro* ptrImage);
    Mat* detectPeople(Mat* ptrImage);
    void processVideo(char* ptrNameInput, char* ptrNameOutput);
};

#endif // HOGDETECTORGPU_H
