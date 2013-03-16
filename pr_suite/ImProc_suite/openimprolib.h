#ifndef OPENPRISL_H
#define OPENPRISL_H
#include "highgui.h"
#include "cv.h"
#include "imageimpro.h"
/*
Interface of the image processing library
*/
class OpenImProLib
{
public:
    OpenImProLib();
    static void runTest();
    virtual void filterCanny(ImageImPro* input, ImageImPro* output, double limInf, double limSup, double apertureSize) = 0;
};

#endif // OPENPRISL_H
