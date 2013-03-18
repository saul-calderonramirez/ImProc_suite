#ifndef OPENIPLIB_OPENCVIMPL_H
#define OPENIPLIB_OPENCVIMPL_H
#include "openimprolib.h"
class OpenImProLib_OpenCvImpl : public OpenImProLib
{
public:
    OpenImProLib_OpenCvImpl();

    void filterCanny(ImageImPro* input, ImageImPro* output, double limInf, double limSup, int apertureSize);
    void filterSobel(ImageImPro* input, ImageImPro* output, int xOrder, int yOrder, int apertureSize);
    ImageImPro* convert2GrayScale(ImageImPro* ptrImage);
    ~OpenImProLib_OpenCvImpl(){}
};

#endif // OPENIPLIB_OPENCVIMPL_H
