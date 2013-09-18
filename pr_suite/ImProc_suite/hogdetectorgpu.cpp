#include "hogdetectorgpu.h"
#define WIN_X 32
#define WIN_Y 32

HOGDetectorGPU::HOGDetectorGPU()
{
}

void HOGDetectorGPU::saveHOGdescriptorsFromDir(char* ptrDirName, char* ptrFileName, int classNum){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (ptrDirName)) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
          if(strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0){

               char fullName[320];
               strcpy(fullName, ptrDirName);
               strcat(fullName, "/");
               strcat(fullName, ent->d_name);
                cout << "Processing file: " << fullName << endl;
               ImageImPro* ptrImage = new ImageImPro_OpenCvImpl(fullName);
               vector<float> descriptors = getHOGdescriptors(ptrImage);
               saveHOGdescriptorsToFile(ptrFileName, descriptors, classNum);
               delete ptrImage;
          }
      }
      closedir (dir);
    } else {
      /* could not open directory */
      perror ("error, no se abrio el directorio");

    }
}


void HOGDetectorGPU::saveHOGdescriptorsToFile(char* ptrName, vector<float> descriptors, int classNum){
    ofstream file;
    file.open (ptrName, std::ios_base::app);
    for(int i = 0; i < descriptors.size(); ++i){
        file << descriptors[i] << " ";
    }
    file << "\n" << classNum << "\n";
    file.close();
}

ImageImPro* HOGDetectorGPU::detectPeople(ImageImPro* ptrImage){
        ImageImPro* ptrGrayInput = ptrImage->getGrayScale();
        GpuMat* ptrGpuMatInput = ptrGrayInput->getGPUMat();
        Mat* ptrMatOutput = ptrGrayInput->getMat();
        vector<float> detector;
        vector<Rect> found;
        Size win_size(48, 96);
        //creates a HOG Descriptor generator with the given window size
        gpu::HOGDescriptor gpu_hog(win_size);
        //gets the coefficients of the SVM trained to detect pedestrians with a window size of 48x96
        detector = gpu::HOGDescriptor::getPeopleDetector48x96();
        gpu_hog.setSVMDetector(detector);
        double hitThreshold = 0.0;
        Size sizeWinStride(8,8);
        double scale0 = 1.05;
        int groupThreshold = 1;
        gpu_hog.detectMultiScale(*ptrGpuMatInput, found, hitThreshold, sizeWinStride, Size(0,0), scale0, groupThreshold);
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
        //Sets the svm trained to detect people
        detector = gpu::HOGDescriptor::getPeopleDetector48x96();

        gpu_hog.setSVMDetector(detector);
        double hitThreshold = 0.9;
        Size sizeWinStride(8,8);
        double scale0 = 1.05;
        int groupThreshold = 2;
        gpu_hog.detectMultiScale(gpuMat, found, hitThreshold, sizeWinStride, Size(0,0), scale0, groupThreshold);
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
        outputVideo.release();
 }

vector<float> HOGDetectorGPU::getHistogramFromBlockDescriptor(vector<float> descriptors, int currCell, int numHistograms, int nBins){
    int firstBin = currCell * nBins;
    vector<float> cellHistogram(nBins);
    int j = 0;
    for(int i = firstBin; i < firstBin + nBins; ++i){
        cellHistogram[j++] = descriptors[i];
    }

    return cellHistogram;
}

double HOGDetectorGPU::getMaxValue(vector<float> array){
    double max = 0;
    for(int i = 0; i < array.size(); ++i){
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

vector<float> HOGDetectorGPU::normalize(vector<float> array){
    double max = getMaxValue(array);
    vector<float> normalized(array.size());
    for(int i = 0; i < array.size(); ++i){
        normalized[i] = array[i] / max;
    }
    return normalized;
}

void drawLine( Mat* ptrImage, Point start, Point end, int intensity ){
  int thickness = 2;
  int lineType = 8;
  line( *ptrImage, start, end, Scalar( intensity ), thickness, lineType );
}

cv::Mat* HOGDetectorGPU::getHistogramImage(vector<float> &histogram){
    int nBins = histogram.size();
    //Image corresponding to a histogram of a cell
    int imDim = 32;
    //inits the image

    int originX = 15;
    int originY = 15;
    int maxDisp = 15;
    ImSize size(imDim, imDim);
    ImageImPro* ptrTemp = new ImageImPro_OpenCvImpl(size, ImageImPro_OpenCvImpl::BIT_8_U, 1);
    Mat* ptrHistImage = ptrTemp->getMat();
    delete ptrTemp;

    vector<float> normalized = histogram;//normalize(histogram);
    float radRangeForOneBin = M_PI/(float)nBins;
    for(int bin = 0; bin < histogram.size(); ++bin){
        float currAngle = bin * radRangeForOneBin + radRangeForOneBin;
        float dirVecX = cos( currAngle );
        float dirVecY = sin( currAngle );
        int strength = (int)(normalized[bin] * 255);
        int x1 = originX - dirVecX * maxDisp;
        int y1 = originY + dirVecY * maxDisp;
        int x2 = originX + dirVecX * maxDisp;
        int y2 = originY - dirVecY * maxDisp;
        drawLine(ptrHistImage, Point(x1, y1), Point(x2, y2), strength);
      //  cout << "curr Strength: " << strength << " angle: " << currAngle << " histogram " << histogram[bin] << endl;

    }
    return ptrHistImage;
}

void copyMat(Mat& tile, Mat& window, int x0Tile, int y0Tile){
    int xWin = 0;
    int yWin = 0;
    cout << "copying: x " << x0Tile << " y: " << y0Tile << endl;
    int winHeight = window.size().height;
    int winWidth = window.size().width;
     for(int xTile = x0Tile; xTile < x0Tile + winHeight; ++xTile){
        yWin = 0;
        for(int yTile = y0Tile; yTile < y0Tile + winWidth; ++yTile){
            tile.at<unsigned char>(xTile, yTile) = window.at<unsigned char>(xWin, yWin++);
           //   tile.at<unsigned char>(0, 0) = window.at<unsigned char>(0, 0);
        }
        xWin++;
    }

}

/*
*@param descriptors: The descriptors of a block
*/
ImageImPro* HOGDetectorGPU::drawBlockHOG(vector<float> descriptors, cv::HOGDescriptor hog){
    int numHistograms = descriptors.size() / hog.nbins;
    cout << "Num histograms: " << numHistograms << endl;
    vector<float> normalized = normalize(descriptors);
    ImageImPro* ptrImage = NULL;
    int cellsPerRow = hog.blockSize.height / hog.cellSize.height;
    int cellsPerCol = hog.blockSize.width / hog.cellSize.width;
    int pixPerCellX = 32;
    int pixPerCellY = 32;
    ImSize size(cellsPerCol * pixPerCellY, cellsPerRow * pixPerCellX);

    ImageImPro* ptrTemp = new ImageImPro_OpenCvImpl( size, ImageImPro_OpenCvImpl::BIT_8_U, 1);
    Mat* ptrHistImage = ptrTemp->getMat();
    delete ptrTemp;
    int currHist = 0;
    for(int row = 0; row < cellsPerRow; ++row){
        for(int col = 0; col < cellsPerCol; ++col){
            vector <float> cellHistogram = getHistogramFromBlockDescriptor(normalized, currHist++, numHistograms, hog.nbins);
            cout << "Current histogram: " << currHist << endl;
            cv::Mat* ptrMat = getHistogramImage(cellHistogram);
            copyMat(*ptrHistImage, *ptrMat, row * pixPerCellX, col * pixPerCellY);
            delete ptrMat;
        }



    }
    ptrImage = new ImageImPro_OpenCvImpl(ptrHistImage);
    return ptrImage;
}


ImageImPro* HOGDetectorGPU:: getDescriptors(ImageImPro* ptrImage){
    ImageImPro* ptrGrayInput = ptrImage->getGrayScale();
    Mat* ptrMatInput = ptrGrayInput->getMat();
    resize(*ptrMatInput, *ptrMatInput, Size(32,32) );
    //GpuMat* ptrGpuMatInput = ptrGrayInput->getGPUMat();
    Size winSize(32, 32);
    //creates a HOG Descriptor generator with the given window size

    cv::HOGDescriptor hog;
    hog.winSize = winSize;
    //gpu::HOGDescriptor gpu_hog(win_size);

    //Tamanio del bloque
    //Hay 3x6 = 18 bloques en una ventana
    //gpu_hog.block_size = Size(16, 16);
    //Hacemos un solo bloque para la ventana
    hog.blockSize = Size(32, 32);

    //Pixeles en los que hay Movimiento de cada bloque para hacer la normalizacion
    //blockStepSize (blockStride), typically 8 pixels shift size
    //gpu_hog.block_stride = Size(8,8);

    hog.blockStride = Size(8, 8);
    //Dimensiones de cada celda
    //gpu_hog.cell_size = Size(8,8);
    //Otro caso
    //32/8 = 4, 4x4 = 16 celdas en un bloque
    hog.cellSize = Size(8, 8);
    //number of bins, 9
    //gpu_hog.nbins = 9;
    //16x9 = 144 elementos en un descriptor
    hog.nbins = 9;
    //Si hay: 9 bins en un histograma de una celda
    //Hay 4 celdas en un bloque: 4x9 = 36 descriptores en un bloque
    //Hay 18 bloques en una ventana: 18x36 = 648 descriptores
    //gpu_hog.computeBlockHistograms();
    //gpu_hog.getDescriptors();
    vector<float> descriptorsValues;
    vector<Point> locations;
    hog.compute( *ptrMatInput, descriptorsValues, Size(0,0), Size(0,0), locations);
    cout << "HOG descriptor size is " << hog.getDescriptorSize() << endl;
    cout << "Found " << descriptorsValues.size() << " descriptor values" << endl;
    ImageImPro* ptrOutput = drawBlockHOG(descriptorsValues, hog);
   // Mat hogImage = get_hogdescriptor_visu(*ptrMatInput, descriptorsValues);

    namedWindow( "HOG", CV_WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "HOG", *(ptrOutput->getMat()));                   // Show our image inside it.*/


    delete ptrMatInput;
    delete ptrGrayInput;


    return NULL;
}




Mat HOGDetectorGPU::get_hogdescriptor_visu(Mat& origImg, vector<float>& descriptorValues, vector<float>& avgDescriptors){
    Mat color_origImg = origImg;
    //cvtColor(origImg, color_origImg, CV_GRAY2RGB);

    float zoomFac = 3;
    Mat visu;
    resize(color_origImg, visu, Size(color_origImg.cols*zoomFac, color_origImg.rows*zoomFac));

    int blockSize       = 16;
    int cellSize        = 8;
    int gradientBinSize = 9;
    int cellsPerBlock = (blockSize / cellSize) * (blockSize / cellSize);
    int avgHistogramSize = (descriptorValues.size() / gradientBinSize) * cellsPerBlock;
    vector<float> temp(avgHistogramSize);
    avgDescriptors = temp;
    float radRangeForOneBin = M_PI/(float)gradientBinSize; // dividing 180° into 9 bins, how large (in rad) is one bin?

    // prepare data structure: 9 orientation / gradient strenghts for each cell
    int cells_in_x_dir = WIN_X / cellSize;
    int cells_in_y_dir = WIN_Y / cellSize;
    int totalnrofcells = cells_in_x_dir * cells_in_y_dir;
    float*** gradientStrengths = new float**[cells_in_y_dir];
    int** cellUpdateCounter   = new int*[cells_in_y_dir];
    for (int y=0; y<cells_in_y_dir; y++)
    {
        gradientStrengths[y] = new float*[cells_in_x_dir];
        cellUpdateCounter[y] = new int[cells_in_x_dir];
        for (int x=0; x<cells_in_x_dir; x++)
        {
            gradientStrengths[y][x] = new float[gradientBinSize];
            cellUpdateCounter[y][x] = 0;

            for (int bin=0; bin<gradientBinSize; bin++)
                gradientStrengths[y][x][bin] = 0.0;
        }
    }

    // nr of blocks = nr of cells - 1
    // since there is a new block on each cell (overlapping blocks!) but the last one
    int blocks_in_x_dir = cells_in_x_dir - 1;
    int blocks_in_y_dir = cells_in_y_dir - 1;

    // compute gradient strengths per cell
    int descriptorDataIdx = 0;
    int cellx = 0;
    int celly = 0;

    for (int blockx=0; blockx<blocks_in_x_dir; blockx++)
    {
        for (int blocky=0; blocky<blocks_in_y_dir; blocky++)
        {
            // 4 cells per block ...
            for (int cellNr=0; cellNr<4; cellNr++)
            {
                // compute corresponding cell nr
                //Cell 0
                int cellx = blockx;
                int celly = blocky;
                //cell 1
                if (cellNr==1) celly++;
                //cell 2
                if (cellNr==2) cellx++;
                if (cellNr==3)
                {
                    cellx++;
                    celly++;
                }

                for (int bin=0; bin<gradientBinSize; bin++)
                {
                    float gradientStrength = descriptorValues[ descriptorDataIdx ];
                    descriptorDataIdx++;

                    gradientStrengths[celly][cellx][bin] += gradientStrength;

                } // for (all bins)


                // note: overlapping blocks lead to multiple updates of this sum!
                // we therefore keep track how often a cell was updated,
                // to compute average gradient strengths
                cellUpdateCounter[celly][cellx]++;

            } // for (all cells)


        } // for (all block x pos)
    } // for (all block y pos)

    int avgHistCounter = 0;
    // compute AVERAGE gradient strengths
    for (int celly=0; celly<cells_in_y_dir; celly++)
    {
        for (int cellx=0; cellx<cells_in_x_dir; cellx++)
        {

            float NrUpdatesForThisCell = (float)cellUpdateCounter[celly][cellx];

            // compute average gradient strenghts for each gradient bin direction
            for (int bin=0; bin<gradientBinSize; bin++)
            {
                gradientStrengths[celly][cellx][bin] /= NrUpdatesForThisCell;
                avgDescriptors[avgHistCounter++] = gradientStrengths[celly][cellx][bin];
            }
        }
    }


    cout << "descriptorDataIdx = " << descriptorDataIdx << endl;

    // draw cells
    for (int celly=0; celly<cells_in_y_dir; celly++)
    {
        for (int cellx=0; cellx<cells_in_x_dir; cellx++)
        {
            int drawX = cellx * cellSize;
            int drawY = celly * cellSize;

            int mx = drawX + cellSize/2;
            int my = drawY + cellSize/2;

            rectangle(visu, Point(drawX*zoomFac,drawY*zoomFac), Point((drawX+cellSize)*zoomFac,(drawY+cellSize)*zoomFac), CV_RGB(100,100,100), 1);

            // draw in each cell all 9 gradient strengths
            for (int bin=0; bin<gradientBinSize; bin++)
            {
                float currentGradStrength = gradientStrengths[celly][cellx][bin];

                // no line to draw?
                if (currentGradStrength==0)
                    continue;

                float currRad = bin * radRangeForOneBin + radRangeForOneBin;

                float dirVecX = cos( currRad );
                float dirVecY = sin( currRad );
                float maxVecLen = cellSize/2;
                float scale = 2.5; // just a visualization scale, to see the lines better

                // compute line coordinates
                float x1 = mx - dirVecX * currentGradStrength * maxVecLen * scale;
                float y1 = my + dirVecY * currentGradStrength * maxVecLen * scale;
                float x2 = mx + dirVecX * currentGradStrength * maxVecLen * scale;
                float y2 = my - dirVecY * currentGradStrength * maxVecLen * scale;

                // draw gradient visualization
                line(visu, Point(x1*zoomFac,y1*zoomFac), Point(x2*zoomFac,y2*zoomFac), CV_RGB(0,255,0), 1);

            } // for (all bins)

        } // for (cellx)
    } // for (celly)


    // don't forget to free memory allocated by helper data structures!
    for (int y=0; y<cells_in_y_dir; y++)
    {
      for (int x=0; x<cells_in_x_dir; x++)
      {
           delete[] gradientStrengths[y][x];
      }
      delete[] gradientStrengths[y];
      delete[] cellUpdateCounter[y];
    }
    delete[] gradientStrengths;
    delete[] cellUpdateCounter;

    return visu;

} // get_hogdescriptor_visu

vector<float> HOGDetectorGPU::getHOGdescriptors(cv::HOGDescriptor& hog, Mat& image){
    resize(image, image, Size(WIN_X,WIN_Y) );
    Mat img;
    cvtColor(image, img, CV_RGB2GRAY);
    hog.winSize.height = WIN_X;
    hog.winSize.width = WIN_Y;
    // Size(128,64), //winSize
    // Size(16,16), //blocksize
    // Size(8,8), //blockStride,
    // Size(8,8), //cellSize,
    // 9, //nbins,
    // 0, //derivAper,
    // -1, //winSigma,
    // 0, //histogramNormType,
    // 0.2, //L2HysThresh,
    // 0 //gammal correction,
    // //nlevels=64
    //);
    vector<float> descriptorsValues;
    vector<Point> locations;
    hog.compute( img, descriptorsValues, Size(0,0), Size(0,0), locations);
    cout << "HOG descriptor size is " << hog.getDescriptorSize() << endl;
    cout << "img dimensions: " << img.cols << " width x " << img.rows << "height" << endl;
    cout << "Found " << descriptorsValues.size() << " descriptor values" << endl;
    cout << "Nr of locations specified : " << locations.size() << endl;
    return descriptorsValues;

}

vector<float> HOGDetectorGPU::getHOGdescriptors(ImageImPro* ptrInput){
    Mat* img_raw = ptrInput->getMat();
    cv::HOGDescriptor hog;
    vector<float> descriptorValues = getHOGdescriptors(hog, *img_raw);
    vector<float> descriptorsAvg(144);
    Mat res =  get_hogdescriptor_visu(*img_raw, descriptorValues,descriptorsAvg );

  /*  namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", res );                   // Show our image inside it.

    waitKey(0);*/
    delete img_raw;
    return descriptorsAvg;
}

