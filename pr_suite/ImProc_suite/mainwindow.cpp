#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    this->ptrScene = new QGraphicsScene;
    this->ptrController = new Controller();
    this->ui->setupUi(this);
    connect(ui->actionOtro_Abrir, SIGNAL(triggered()), this, SLOT(on_mnOpenImage_clicked()));
}

void MainWindow::showImage(QImage* qImage){
     QPixmap pixMap = QPixmap::fromImage(*qImage);
     this->ptrScene->addPixmap(pixMap);
     this->ui->imgDisplay->setScene(this->ptrScene);
     this->ui->imgDisplay->show();
}

MainWindow::~MainWindow(){
    delete ui;
    delete this->ptrController;
}

void MainWindow::on_mnOpenImage_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Files (*.*)"));
    if(fileName != NULL){
        string nameStd = fileName.toStdString();
        char *ptrName = new char[nameStd.size() + 1];
        ptrName[nameStd.size()] = 0;
        memcpy(ptrName, nameStd.c_str(), nameStd.size());
        cout << "Image to load: " << ptrName << endl;
        this->ptrController->loadImage(ptrName);
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
}

void MainWindow::on_btnCannyFilter_clicked(){
    try{
        this->ptrController->applyFilterCanny();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}

void MainWindow::on_btnSobelFilter_clicked(){
    try{
        this->ptrController->applyFilterSobel();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}

void MainWindow::on_btnUmbBin_clicked(){
    try{
        this->ptrController->applyBinaryThreshold();
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}

void MainWindow::on_btnLoadDefImage_clicked(){
    try{
        this->ptrController->loadImage((char*)DEF_IMAGE);
        QImage* qImage = this->ptrController->getImage()->getQImage();
        showImage(qImage);
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }

}

void MainWindow::on_btnContour_clicked(){
    try{
        cout << "hizo click en find contour" << endl;
        this->ptrController->findCountour();
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }

}

void MainWindow::on_btnSegWaterSheds_2_clicked(){
    try{
        this->ptrController->runBenchmarks();
    }
    catch(Controller::ControllerException contExc){
        cout << contExc.what() << endl;
    }
}
