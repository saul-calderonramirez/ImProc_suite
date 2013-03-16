#include "openimprolib.h"

OpenImProLib::OpenImProLib(){
}

void OpenImProLib::runTest(){
    IplImage* imagenGris = cvLoadImage("left02.jpg");
    IplImage* imagenCanny = cvCreateImage(cvGetSize(imagenGris), IPL_DEPTH_8U, 1);
    double limInf = 10;
    double limSup = 500;
    double apertura = 3;
    cvCanny(imagenGris, imagenCanny, limInf, limSup, apertura);
    cvNamedWindow( "SinFiltro", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Filtrada", CV_WINDOW_AUTOSIZE );
    cvShowImage("Filtrada", imagenCanny);
    cvShowImage("SinFiltro", imagenGris);
    cvWaitKey(0);
    cvReleaseImage( &imagenGris );
    cvReleaseImage( &imagenCanny );
    cvDestroyWindow( "SinFiltro" );
    cvDestroyWindow( "Filtrada" );
}
