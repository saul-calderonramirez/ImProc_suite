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
    void filterCanny(ImageImPro* input, ImageImPro* output, double limInf, double limSup, int apertureSize);
    void filterSobel(ImageImPro* input, ImageImPro* output, int xOrder, int yOrder, int apertureSize);
    void applyThreshold(ImageImPro* input, ImageImPro* output, double threshold, double maxValue, ThresholdType typeThresh);
    ImageImPro* convert2GrayScale(ImageImPro* ptrImage);
    ~OpenImProLib_OpenCvImpl(){}
};

#endif // OPENIPLIB_OPENCVIMPL_H
