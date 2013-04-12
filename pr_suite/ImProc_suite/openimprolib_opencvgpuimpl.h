#ifndef OPENIMPROLIB_OPENCVGPUIMPL_H
#define OPENIMPROLIB_OPENCVGPUIMPL_H
#include "includes.h"
#include "openimprolib.h"
class OpenImProLib_OpenCVGPUimpl: public OpenImProLib
{
public:
    OpenImProLib_OpenCVGPUimpl();
    ImageImPro* filterCanny(ImageImPro* input, double limInf, double limSup, int apertureSize);
    ImageImPro* filterSobel(ImageImPro* input, int xOrder, int yOrder, int apertureSize);
    ImageImPro* applyThreshold(ImageImPro* input, double threshold, double maxValue, ThresholdType typeThresh);
    ImageImPro* convert2GrayScale(ImageImPro* ptrImage);
};

#endif // OPENIMPROLIB_OPENCVGPUIMPL_H
