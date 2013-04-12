#ifndef UNITTESTSOCV_OCL_H
#define UNITTESTSOCV_OCL_H
#include "includes.h"
using namespace cv;


class UnitTestsOCV
{

public:
    UnitTestsOCV();

    static int getMilliCount(){
        timeb tb;
        ftime(&tb);
        int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
        return nCount;
    }

    static int getMilliSpan(int nTimeStart){
        int nSpan = getMilliCount() - nTimeStart;
        if(nSpan < 0)
            nSpan += 0x100000 * 1000;
        return nSpan;
    }


    static void testOCV_OCL_1(){
        /*const char* wndname = "Original";
        const char* wndname2 = "Pyrdown";
        ocl::setBinpath("/usr/lib/x86_64-linux-gnu/");
        vector<ocl::Info> info;
        CV_Assert(ocl::getDevice(info));
        std::cout<<"Init hecho!"<< std::endl;
        Mat image = imread("baboon.jpg", CV_LOAD_IMAGE_GRAYSCALE);
        cv::ocl::oclMat pyr_ocl;
        cv::ocl::oclMat input(image);
        int startMilli = getMilliCount();
       // ocl::pyrDown(ocl::oclMat(image), pyr_ocl);
        ocl::Canny(input, pyr_ocl, 100, 300, 3);
        int endMilli = getMilliSpan(startMilli);
        std::cout<< "Time OCL pyrDown: " << endMilli << std::endl;
        Mat down = Mat(pyr_ocl);
        namedWindow( wndname, 1 );
        imshow(wndname, image);
        int c = waitKey();
        namedWindow( wndname2, 1 );
        imshow(wndname2, down);
        c = waitKey();*/
    }
    static void testOCV_GPU_2(){
        try{
            Mat src_host = cv::imread("baboon.jpg", CV_LOAD_IMAGE_GRAYSCALE);
            gpu::GpuMat dst, src;
            int startMilli = getMilliCount();
            src.upload(src_host);
            gpu::threshold(src, dst, 128.0, 255.0, CV_THRESH_BINARY);
            Mat result_host = (Mat)dst;
            int endMilli = getMilliSpan(startMilli);
            std::cout<< "Time OCL pyrDown: " << endMilli << std::endl;
            namedWindow( "Result", 1 );
            imshow("Result", result_host);
            waitKey();
        }
        catch(const cv::Exception& ex){
                std::cout << "Error: " << ex.what() << std::endl;
        }
    }
};

#endif // UNITTESTSOCV_OCL_H
