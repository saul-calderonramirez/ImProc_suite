#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "controller.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Controller* ptrController;
    QGraphicsScene* ptrScene;
private slots:
    void on_btnCannyFilter_clicked();
    void showImage(QImage* qImage);
    void on_btnSobelFilter_clicked();

    void on_btnUmbBin_clicked();

    void on_btnLoadDefImage_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H