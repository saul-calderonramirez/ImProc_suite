#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Controller* ptrController;
public:
    QGraphicsScene* ptrScene;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showImage(QImage* qImage);
    
private slots:
    void on_btnCannyFilter_clicked();
    void on_btnLoadDefImage_clicked();

    void on_btnSobelFilter_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
