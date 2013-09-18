#ifndef OPENPRISL_H
#define OPENPRISL_H

#include "imageimpro_opencvimpl.h"
#include "includes.h"
/*
Interface of the image processing library
*/


class OpenImProLib
{
public:
    enum ThresholdType { BINARY_THRESH, BINARY_INV_THRESH, TRUNC_THRESH, TO_ZERO_THRESH, TO_ZERO_INV_THRESH};
    OpenImProLib();
    static void runTest();
    /*
    *The Canny filter detects the edges on an images
    *Calculates the first derivative in the four directions, and applies an hysteresis threshold
    *Hysteresis threshold: Has an Upper and Lower boundary, U and L. If the gradient Gi > U at pixel Pi, then Pi is classified as an edge
    *if  L < Gi < U, and Gi is connected to a Pixel Pj classified as an edge, then Pi is also classified as an edge
    *Otherwise the Pixel Pi is part of the background
    *@param input, input image, should be in grayscale (one channel)
    *@param output, binary image, with one channel. It is an empty pointer, the image is created with 32F, 1 channel format
    *@param limInf, Lower boundary L
    *@param limSup, Upper boundary U
    *@param appertureSize, defines the size of the convolution window. Odd numbers 3, 5 and 7 must be used
    *A smaller window is more sensitive to noise
    *@return Binary Image with the edges white and the rest of the image black
    */
    virtual ImageImPro* filterCanny(ImageImPro* input, double limInf, double limSup, int apertureSize) = 0;
    /*
    *The sobel filter is an approximation to a derivative, it can apply first or second order in both coordinates in an image
    *First, the sobel operator applies a gaussian filter, in order to smooth the image
    *Then it calculates the derivative, and umbralizes the image
    *@param input, the input image, could be grayscale or RGB
    *@param output, the output image must have at least 16 bit pixel representation, to avoid overflow
    *@param xOrder, the derivative order for the X axis
    *@param yOrder, the derivative order for the Y axis
    *@param apertureSize, size of the filter window, if the size is 3, the scharr filter is used, less sensitive to noise
    */
    virtual ImageImPro* filterSobel(ImageImPro* input, int xOrder, int yOrder, int apertureSize) = 0;
    /*
    * The threshold operator classifies each pixel on the input image Pi, comparing Pi < threshold, and in the output applyng the type
    * of threshold selected by the user
    *@param input, input image must have ideally a dimmension of 1, otherwise the grayscaled image will be calculated
    *@param output, output image, with the threshold applied, It is an empty pointer, the image is created with 8U, 1 channel format
    *@param limInf, Lower boundary L
    *@param threshold, the threshold checked in every pixel
    *@param maxValue, the maxValue of the output image, assigned according to the type of threshold
    *@param typeThresh, the type of the threshold could be:
    *BINARY_THRESH: Output_i = (Input_i > Thresh) Max:0
    *BINARY_INV_THRESH: Output_i = (Input_i > Thresh) 0:Max
    *TRUNC_THRESH: Output_i = (Input_i > Thresh) M:Input_i
    *TO_ZERO_INV_THRESH: Output_i = (Input_i > Thresh) 0:Input_i
    *TO_ZERO_INV_THRESH: Output_i = (Input_i > Thresh) Input_i:0
    */
    virtual ImageImPro* applyThreshold(ImageImPro* input, double threshold, double maxValue, ThresholdType typeThresh) = 0;

    virtual ImageImPro* filterGauss(ImageImPro* ptrInput, double sigmaX, double sigmaY, int apertureSize) = 0;

    virtual ImageImPro* thresholdEqualsRGB(ImageImPro* ptrInput, RGB_VALUE threshold) = 0;
    //8 bit 1 layer image is received
    //returns an image with 1's where the object is and 0
    virtual ImageImPro** getCounturedObjectMask(ImageImPro* ptrMask, ImageImPro* ptrInput, int objectMaskTag) = 0;

    virtual vector<double> getDensityFunction(ImageImPro* ptrInput, ImageImPro* ptrMask, int layer) = 0;
    virtual double getBattacharyaDistance() = 0;

    virtual ~OpenImProLib(){}
};

#endif
