#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ptrScene = new QGraphicsScene;
        ptrController = new Controller();
    ui->setupUi(this);
}

void MainWindow::showImage(QImage* qImage){
     QPixmap pixMap = QPixmap::fromImage(*qImage);
     this->ptrScene->addPixmap(pixMap);
     ui->imgDisplay->setScene(this->ptrScene);
     ui->imgDisplay->show();
}

MainWindow::~MainWindow(){
    delete ui;
    delete this->ptrController;
}

void MainWindow::on_btnCannyFilter_clicked(){
    try{
        ptrController->applyFilterCanny();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}

void MainWindow::on_btnSobelFilter_clicked(){
    try{
        ptrController->applyFilterSobel();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}

void MainWindow::on_btnUmbBin_clicked(){
    try{
        ptrController->applyBinaryThreshold();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}

void MainWindow::on_btnLoadDefImage_clicked(){
    try{
        ptrController->loadDefaultImage();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }

}