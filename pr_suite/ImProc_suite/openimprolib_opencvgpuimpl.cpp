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
ImageImPro* OpenImProLib_OpenCVGPUimpl::filterSobel(ImageImPro* ptrInput, int xOrder, int yOrder, int apertureSize){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
    }
    Mat* ptrMatInput = ptrGrayScaleInput->getMat();
    GpuMat gpuMatInput;
    GpuMat* ptrGpuMatOutput = new GpuMat();
    //loads the matrix to the device
    gpuMatInput.upload(*ptrMatInput);
    gpu::Sobel(gpuMatInput, *ptrGpuMatOutput,CV_8U, xOrder, yOrder, apertureSize);
    Mat* ptrMatOutput = new Mat(*ptrGpuMatOutput);

    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);

    delete ptrMatInput;
    delete ptrGpuMatOutput;
    delete ptrMatOutput;

    return ptrImProOutput;
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
    //CORREGIR, EL TYPETHRESH DEBE SER DEL TIPO DEL OCV GPU
    gpu::threshold(gpuMatInput, *ptrGpuMatOutput, threshold, maxValue, typeThresh);


    Mat* ptrMatOutput = new Mat(*ptrGpuMatOutput);



    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);

    delete ptrMatInput;
    delete ptrGpuMatOutput;
    delete ptrMatOutput;

    return ptrImProOutput;
}

ImageImPro* OpenImProLib_OpenCVGPUimpl::filterGauss(ImageImPro* ptrInput, double sigmaX, double sigmaY, int apertureSize){
    ImageImPro* ptrGrayScaleInput = ptrInput;
    if(ptrInput->getChannels() > 1){
            ptrGrayScaleInput = ptrInput->getGrayScale();
    }
    Mat* ptrMatInput = ptrGrayScaleInput->getMat();
    GpuMat gpuMatInput;
    GpuMat* ptrGpuMatOutput = new GpuMat();
    Size size;
    size.width = apertureSize;
    size.height = apertureSize;
    gpuMatInput.upload(*ptrMatInput);
    gpu::GaussianBlur(gpuMatInput, *ptrGpuMatOutput, size, sigmaX, sigmaY);
    Mat* ptrMatOutput = new Mat(*ptrGpuMatOutput);

    ImageImPro* ptrImProOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);



    delete ptrMatInput;
    delete ptrGpuMatOutput;
    delete ptrMatOutput;


    return ptrImProOutput;


}
