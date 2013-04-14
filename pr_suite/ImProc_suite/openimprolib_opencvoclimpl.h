#ifndef OPENIMPROLIB_OPENCVOCLIMPL_H
#define OPENIMPROLIB_OPENCVOCLIMPL_H
#include "openimprolib.h"
#include "includes.h"
class OpenImProLib_OpenCVOCLimpl: public OpenImProLib
{
public:
    OpenImProLib_OpenCVOCLimpl();
    ImageImPro* filterCanny(ImageImPro* input, double limInf, double limSup, int apertureSize);
    ImageImPro* filterSobel(ImageImPro* input, int xOrder, int yOrder, int apertureSize);
    ImageImPro* filterGauss(ImageImPro* ptrInput, double sigmaX, double sigmaY, int apertureSize);
    ImageImPro* applyThreshold(ImageImPro* input, double threshold, double maxValue, ThresholdType typeThresh);
    ImageImPro* convert2GrayScale(ImageImPro* ptrImage);
};

#endif // OPENIMPROLIB_OPENCVOCLIMPL_H
