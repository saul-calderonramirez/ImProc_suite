#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  ui(new Ui::MainWindow){
    ptrScene = new QGraphicsScene;
    ptrController = new Controller();
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete this->ptrController;
    delete ui;
}

void MainWindow::showImage(QImage* qImage){
     QPixmap pixMap = QPixmap::fromImage(*qImage);
     this->ptrScene->addPixmap(pixMap);
     ui->imgDisplay->setScene(this->ptrScene);
     ui->imgDisplay->show();
}

void MainWindow::on_btnCannyFilter_clicked(){
    Controller::Status status = ptrController->applyFilterCanny();
    if(status == Controller::OK){
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
        delete qImage;
    }
}



void MainWindow::on_btnLoadDefImage_clicked(){
    Controller::Status status = ptrController->loadDefaultImage();
    if(status == Controller::OK){
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
        //delete qImage;
    }
}

void MainWindow::on_btnSobelFilter_clicked(){
    Controller::Status status = ptrController->applyFilterSobel();

    if(status == Controller::OK){
       /* QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
        delete qImage;*/
    }
}


