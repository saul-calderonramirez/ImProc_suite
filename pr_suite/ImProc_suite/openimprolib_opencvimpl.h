#ifndef OPENIPLIB_OPENCVIMPL_H
#define OPENIPLIB_OPENCVIMPL_H
#include "openimprolib.h"
#include "includes.h"

using namespace std;
class OpenImProLib_OpenCvImpl : public OpenImProLib
{
private:
    int imProThresh2CvThresh(ThresholdType thresholdType);

public:
    OpenImProLib_OpenCvImpl();
    ImageImPro* filterCanny(ImageImPro* input, double limInf, double limSup, int apertureSize);
    ImageImPro* filterSobel(ImageImPro* input, int xOrder, int yOrder, int apertureSize);
    ImageImPro* applyThreshold(ImageImPro* input, double threshold, double maxValue, ThresholdType typeThresh);
    ImageImPro* convert2GrayScale(ImageImPro* ptrImage);
    ~OpenImProLib_OpenCvImpl(){}
};

#endif // OPENIPLIB_OPENCVIMPL_H
