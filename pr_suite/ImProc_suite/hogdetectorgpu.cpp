#include "hogdetectorgpu.h"

HOGDetectorGPU::HOGDetectorGPU()
{
}

ImageImPro* HOGDetectorGPU::detectPeople(ImageImPro* ptrImage){
        ImageImPro* ptrGrayInput = ptrImage->getGrayScale();
        GpuMat* ptrGpuMatInput = ptrGrayInput->getGPUMat();
        Mat* ptrMatOutput = ptrGrayInput->getMat();
        vector<float> detector;
        vector<Rect> found;
        Size win_size(48, 96);
        gpu::HOGDescriptor gpu_hog(win_size);

        detector = gpu::HOGDescriptor::getPeopleDetector48x96();
        gpu_hog.setSVMDetector(detector);
        gpu_hog.detectMultiScale(*ptrGpuMatInput, found, 0.9, Size(8,8), Size(0,0), 1.05, 2);
        for(int i = 0; i < (int)found.size(); ++i){
            Rect current = found[i];
            rectangle(*ptrMatOutput, current.tl(), current.br(),  CV_RGB(0, 255, 0), 3);
        }
        ImageImPro* ptrOutput = new ImageImPro_OpenCvImpl(ptrMatOutput);

        delete ptrGpuMatInput;
        delete ptrMatOutput;
        delete ptrGrayInput;

        return ptrOutput;
    }

    static void initDetector(){

    }
//More eficient version, designed for video processing
Mat* HOGDetectorGPU::detectPeople(Mat* ptrMat){
        Mat* ptrMatImage = ptrMat;
        gpu::GpuMat gpuMat;
        gpuMat.upload(*ptrMatImage);
        vector<float> detector;
        vector<Rect> found;
        Size win_size(48, 96);
        gpu::HOGDescriptor gpu_hog(win_size);
        detector = gpu::HOGDescriptor::getPeopleDetector48x96();
        gpu_hog.setSVMDetector(detector);
        gpu_hog.detectMultiScale(gpuMat, found, 0.9, Size(8,8), Size(0,0), 1.05, 2);
        for(int i = 0; i < (int)found.size(); ++i){
            Rect current = found[i];
            rectangle(*ptrMatImage, current.tl(), current.br(),  CV_RGB(0, 255, 0), 3);
        }
        return ptrMatImage;
    }

void HOGDetectorGPU::processVideo(char* ptrNameInput, char* ptrNameOutput){
        VideoCapture inputVideo(ptrNameInput);        
        VideoWriter outputVideo;
        Size sizeVideo = Size((int) inputVideo.get(CV_CAP_PROP_FRAME_WIDTH),(int) inputVideo.get(CV_CAP_PROP_FRAME_HEIGHT));
        Mat* ptrMatOut;
        outputVideo.open(ptrNameOutput, CV_FOURCC('x','v','i','d'), inputVideo.get(CV_CAP_PROP_FPS), sizeVideo, true);
        Mat* ptrMat;
        vector<Mat> spl;
        while(inputVideo.grab()){
            ptrMat = new Mat();
            inputVideo >> *ptrMat; // get a new frame from video
            Mat finalMat;
            split(*ptrMat, spl);
            cvtColor(*ptrMat, *ptrMat, CV_BGR2GRAY);
            ptrMatOut = detectPeople(ptrMat);
            spl[0] = *(ptrMatOut);
            spl[1] = *(ptrMatOut);
            spl[2] = *(ptrMatOut);
            merge(spl, finalMat);
            outputVideo << finalMat;
            imshow("edges", *(ptrMatOut));
            if(waitKey(30) >= 0) break;
            //Deletes the processed frame
            delete ptrMatOut;

        }
    }
