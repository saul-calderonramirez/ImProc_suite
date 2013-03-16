#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Controller* ptrController;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnCannyFilter_clicked();

    void on_btnLoadDefImage_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
