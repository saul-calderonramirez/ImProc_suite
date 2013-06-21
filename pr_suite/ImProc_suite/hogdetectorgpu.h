#ifndef HOGDETECTORGPU_H
#define HOGDETECTORGPU_H
#include "imageimpro_opencvimpl.h"
#define PIX_BLOCK_X 32
#define PIX_BLOCK_Y 32
#define PIX_CELL_X 8
#define PIX_CELL_Y 8
class HOGDetectorGPU{

public:
    HOGDetectorGPU();
    ImageImPro* detectPeople(ImageImPro* ptrImage);
    Mat* detectPeople(Mat* ptrImage);
    void processVideo(char* ptrNameInput, char* ptrNameOutput);
    ImageImPro* getDescriptors(ImageImPro* ptrImage);

    vector<float> getHistogramFromBlockDescriptor(vector<float> descriptors, int currCell, int numHistograms, int nBins);

    double getMaxValue(vector<float> array);

    vector<float> normalize(vector<float> array);

    cv::Mat* getHistogramImage(vector<float> &histogram);

    cv::Mat get_hogdescriptor_visu(Mat& origImg, vector<float>& descriptorValues, vector<float>& avDescriptors);

    vector<float> getHOGdescriptors(cv::HOGDescriptor& hog, Mat& image);

    vector<float> getHOGdescriptors(ImageImPro* ptr);

    void saveHOGdescriptorsToFile(char* ptrName, vector<float> descriptors, int classNum);

    void saveHOGdescriptorsFromDir(char* ptrDirName, char *ptrFileName, int classNum);
    /*
    *@param descriptors: The descriptors of a block
    */
    ImageImPro* drawBlockHOG(vector<float> descriptors, cv::HOGDescriptor hog);
};

#endif
