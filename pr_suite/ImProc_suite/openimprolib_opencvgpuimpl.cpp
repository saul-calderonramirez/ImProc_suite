#include "openimprolib_opencvgpuimpl.h"
using namespace gpu;
OpenImProLib_OpenCVGPUimpl::OpenImProLib_OpenCVGPUimpl(){
}



ImageImPro* OpenImProLib_OpenCVGPUimpl::filterCanny(ImageImPro* ptrInput, double limInf, double limSup, int apertureSize){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
    }
    Mat* ptrMatInput = ptrGrayScaleInput->getMat();
    GpuMat gpuMatInput;
    GpuMat* ptrGpuMatOutput = new GpuMat();

    gpuMatInput.upload(*ptrMatInput);
    gpu::Canny(gpuMatInput, *ptrGpuMatOutput, limInf, limSup, apertureSize);
    Mat* ptrMatOutput = new Mat(*ptrGpuMatOutput);

    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);

    delete ptrMatInput;
    delete ptrGpuMatOutput;
    delete ptrMatOutput;

    return ptrImProOutput;
}
ImageImPro* OpenImProLib_OpenCVGPUimpl::filterSobel(ImageImPro* input, int xOrder, int yOrder, int apertureSize){
    return NULL;
}
ImageImPro* OpenImProLib_OpenCVGPUimpl::applyThreshold(ImageImPro* ptrInput, double threshold, double maxValue, ThresholdType typeThresh){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
    }
    Mat* ptrMatInput = ptrGrayScaleInput->getMat();
    GpuMat gpuMatInput;
    GpuMat* ptrGpuMatOutput = new GpuMat();

    gpuMatInput.upload(*ptrMatInput);
    gpu::threshold(gpuMatInput, *ptrGpuMatOutput, threshold, maxValue, typeThresh);
    //(ptrCvInputGray, ptrCvOutput, threshold, maxValue, cvThresholdType)

    Mat* ptrMatOutput = new Mat(*ptrGpuMatOutput);

    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);

    delete ptrMatInput;
    delete ptrGpuMatOutput;
    delete ptrMatOutput;

    return ptrImProOutput;
}
