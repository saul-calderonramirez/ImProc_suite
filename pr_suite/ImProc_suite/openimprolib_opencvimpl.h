#ifndef OPENIPLIB_OPENCVIMPL_H
#define OPENIPLIB_OPENCVIMPL_H
#include "openimprolib.h"
class OpenImProLib_OpenCvImpl : public OpenImProLib
{
public:
    OpenImProLib_OpenCvImpl();
    void filterCanny(ImageImPro* input, ImageImPro* output, double limInf, double limSup, double apertureSize);
};

#endif // OPENIPLIB_OPENCVIMPL_H
