#ifndef OPENPRISL_H
#define OPENPRISL_H
#include "highgui.h"
#include "cv.h"
#include "imageimpro_opencvimpl.h"
/*
Interface of the image processing library
*/
class OpenImProLib
{
public:
    OpenImProLib();
    static void runTest();
    /*
    *The Canny filter detects the edges on an images
    *Calculates the first derivative in the four directions, and applies an hysteresis threshold
    *Hysteresis threshold: Has an Upper and Lower boundary, U and L. If the gradient Gi > U at pixel Pi, then Pi is classified as an edge
    *if  L < Gi < U, and Gi is connected to a Pixel Pj classified as an edge, then Pi is also classified as an edge
    *Otherwise the Pixel Pi is part of the background
    *@param input, input image, should be in grayscale (one channel)
    *@param output, binary image, with one channel
    *@param limInf, Lower boundary L
    *@param limSup, Upper boundary U
    *@param appertureSize, defines the size of the convolution window. Odd numbers 3, 5 and 7 must be used
    *A smaller window is more sensitive to noise
    *@return Binary Image with the edges white and the rest of the image black
    */
    virtual void filterCanny(ImageImPro* input, ImageImPro* output, double limInf, double limSup, int apertureSize) = 0;
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
    virtual void filterSobel(ImageImPro* input, ImageImPro* output, int xOrder, int yOrder, int apertureSize) = 0;
    virtual ImageImPro* convert2GrayScale(ImageImPro* ptrImage) = 0;
    virtual ~OpenImProLib(){}
};

#endif // OPENPRISL_H
