/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Apr 14 13:28:31 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_Imagen;
    QAction *actionOtro_Abrir;
    QWidget *centralwidget;
    QGraphicsView *imgDisplay;
    QGroupBox *groupBox_2;
    QToolButton *btnUmbBin;
    QToolButton *btnSegLocal;
    QToolButton *btnContour;
    QToolButton *btnLoadDefImage;
    QGroupBox *groupBox;
    QToolButton *btnCannyFilter;
    QToolButton *btnSobelFilter;
    QToolButton *btnGaussFilter;
    QToolButton *btnSegWaterSheds_2;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionAbrir_Imagen = new QAction(MainWindow);
        actionAbrir_Imagen->setObjectName(QString::fromUtf8("actionAbrir_Imagen"));
        actionOtro_Abrir = new QAction(MainWindow);
        actionOtro_Abrir->setObjectName(QString::fromUtf8("actionOtro_Abrir"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        imgDisplay = new QGraphicsView(centralwidget);
        imgDisplay->setObjectName(QString::fromUtf8("imgDisplay"));
        imgDisplay->setGeometry(QRect(250, 20, 531, 501));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 210, 191, 171));
        btnUmbBin = new QToolButton(groupBox_2);
        btnUmbBin->setObjectName(QString::fromUtf8("btnUmbBin"));
        btnUmbBin->setGeometry(QRect(20, 30, 141, 31));
        btnSegLocal = new QToolButton(groupBox_2);
        btnSegLocal->setObjectName(QString::fromUtf8("btnSegLocal"));
        btnSegLocal->setGeometry(QRect(20, 80, 141, 28));
        btnContour = new QToolButton(groupBox_2);
        btnContour->setObjectName(QString::fromUtf8("btnContour"));
        btnContour->setGeometry(QRect(20, 120, 141, 28));
        btnSegLocal->raise();
        btnUmbBin->raise();
        btnContour->raise();
        btnLoadDefImage = new QToolButton(centralwidget);
        btnLoadDefImage->setObjectName(QString::fromUtf8("btnLoadDefImage"));
        btnLoadDefImage->setGeometry(QRect(30, 460, 171, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 191, 161));
        btnCannyFilter = new QToolButton(groupBox);
        btnCannyFilter->setObjectName(QString::fromUtf8("btnCannyFilter"));
        btnCannyFilter->setGeometry(QRect(20, 30, 141, 28));
        btnSobelFilter = new QToolButton(groupBox);
        btnSobelFilter->setObjectName(QString::fromUtf8("btnSobelFilter"));
        btnSobelFilter->setGeometry(QRect(20, 80, 141, 28));
        btnGaussFilter = new QToolButton(groupBox);
        btnGaussFilter->setObjectName(QString::fromUtf8("btnGaussFilter"));
        btnGaussFilter->setGeometry(QRect(20, 130, 141, 28));
        btnSegWaterSheds_2 = new QToolButton(centralwidget);
        btnSegWaterSheds_2->setObjectName(QString::fromUtf8("btnSegWaterSheds_2"));
        btnSegWaterSheds_2->setGeometry(QRect(50, 420, 141, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 33));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionOtro_Abrir);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAbrir_Imagen->setText(QApplication::translate("MainWindow", "Abrir Imagen", 0, QApplication::UnicodeUTF8));
        actionOtro_Abrir->setText(QApplication::translate("MainWindow", "Abrir Imagen", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Umbralizacion", 0, QApplication::UnicodeUTF8));
        btnUmbBin->setText(QApplication::translate("MainWindow", "Binaria", 0, QApplication::UnicodeUTF8));
        btnSegLocal->setText(QApplication::translate("MainWindow", "Local", 0, QApplication::UnicodeUTF8));
        btnContour->setText(QApplication::translate("MainWindow", "Contorno", 0, QApplication::UnicodeUTF8));
        btnLoadDefImage->setText(QApplication::translate("MainWindow", "Imagen por Defecto", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Filtros", 0, QApplication::UnicodeUTF8));
        btnCannyFilter->setText(QApplication::translate("MainWindow", "Filtro de Canny", 0, QApplication::UnicodeUTF8));
        btnSobelFilter->setText(QApplication::translate("MainWindow", "Filtro de Sobel", 0, QApplication::UnicodeUTF8));
        btnGaussFilter->setText(QApplication::translate("MainWindow", "Filtro de Gauss", 0, QApplication::UnicodeUTF8));
        btnSegWaterSheds_2->setText(QApplication::translate("MainWindow", "Benchmarks", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
