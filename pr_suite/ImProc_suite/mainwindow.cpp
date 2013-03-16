#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  ui(new Ui::MainWindow){
    ptrController = new Controller();
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete this->ptrController;
    delete ui;
}

void MainWindow::on_btnCannyFilter_clicked()
{




}

void MainWindow::on_btnLoadDefImage_clicked(){
    QGraphicsScene *scene = new QGraphicsScene;
    QImage* image = ptrController->runTest1();
    QPixmap pixMap = QPixmap::fromImage(*image);
    scene->addPixmap(pixMap);
    ui->imgDisplay->setScene(scene);
    ui->imgDisplay->show();
}
