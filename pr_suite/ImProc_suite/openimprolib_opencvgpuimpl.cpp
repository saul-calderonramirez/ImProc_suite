#include "openimprolib_opencvgpuimpl.h"
using namespace gpu;
OpenImProLib_OpenCVGPUimpl::OpenImProLib_OpenCVGPUimpl(){
}



ImageImPro* OpenImProLib_OpenCVGPUimpl::filterCanny(ImageImPro* ptrInput, double limInf, double limSup, int apertureSize){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    bool converted = false;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
            converted = true;
    }
    GpuMat* ptrGpuMatOutput = new GpuMat();
    GpuMat* ptrGpuMatInput = ptrGrayScaleInput->getGPUMat();
    gpu::Canny(*ptrGpuMatInput, *ptrGpuMatOutput, limInf, limSup, apertureSize);
    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrGpuMatOutput);
    //frees memory
    if(converted)delete ptrGrayScaleInput;
    delete ptrGpuMatOutput;
    delete ptrGpuMatInput;
    return ptrImProOutput;
}

ImageImPro* OpenImProLib_OpenCVGPUimpl::filterSobel(ImageImPro* ptrInput, int xOrder, int yOrder, int apertureSize){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    bool converted = false;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
            converted = true;
    }
    GpuMat* ptrGpuMatOutput = new GpuMat();
    GpuMat* ptrGpuMatInput = ptrGrayScaleInput->getGPUMat();
    gpu::Sobel(*ptrGpuMatInput, *ptrGpuMatOutput, CV_8U, xOrder, yOrder, apertureSize);
    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrGpuMatOutput);
    if(converted)delete ptrGrayScaleInput;
    delete ptrGpuMatOutput;
    delete ptrGpuMatInput;
    return ptrImProOutput;
}

ImageImPro* OpenImProLib_OpenCVGPUimpl::applyThreshold(ImageImPro* ptrInput, double threshold, double maxValue, ThresholdType typeThresh){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    bool converted = false;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
            converted = true;
    }
    GpuMat* ptrGpuMatOutput = new GpuMat();
    GpuMat* ptrGpuMatInput = ptrGrayScaleInput->getGPUMat();
    //CORREGIR, EL TYPETHRESH DEBE SER DEL TIPO DEL OCV GPU
    gpu::threshold(*ptrGpuMatInput, *ptrGpuMatOutput, threshold, maxValue, typeThresh);
    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrGpuMatOutput);
    if(converted)delete ptrGrayScaleInput;
    delete ptrGpuMatOutput;
    delete ptrGpuMatInput;
    return ptrImProOutput;
}

ImageImPro* OpenImProLib_OpenCVGPUimpl::filterGauss(ImageImPro* ptrInput, double sigmaX, double sigmaY, int apertureSize){
    Size size;
    size.width = apertureSize;
    size.height = apertureSize;
    GpuMat* ptrGpuMatOutput = new GpuMat();
    GpuMat* ptrGpuMatInput = ptrInput->getGPUMat();
    gpu::GaussianBlur(*ptrGpuMatInput, *ptrGpuMatOutput, size, sigmaX, sigmaY);
    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrGpuMatOutput);
    delete ptrGpuMatOutput;
    delete ptrGpuMatInput;
    return ptrImProOutput;
}
