/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 15 20:37:29 2013
**      by: Qt User Interface Compiler version 4.8.3
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
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_Imagen;
    QAction *actionGuardar_Imagen;
    QAction *actionGuardar_Imagen_Como;
    QAction *actionSobre;
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QToolButton *btnSegStd;
    QToolButton *btnSegLocal;
    QToolButton *btnSegWaterSheds;
    QGraphicsView *imgDisplay;
    QGroupBox *groupBox;
    QToolButton *btnCannyFilter;
    QToolButton *btnSobelFilter;
    QToolButton *btnLoadDefImage;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(804, 580);
        actionAbrir_Imagen = new QAction(MainWindow);
        actionAbrir_Imagen->setObjectName(QString::fromUtf8("actionAbrir_Imagen"));
        actionGuardar_Imagen = new QAction(MainWindow);
        actionGuardar_Imagen->setObjectName(QString::fromUtf8("actionGuardar_Imagen"));
        actionGuardar_Imagen_Como = new QAction(MainWindow);
        actionGuardar_Imagen_Como->setObjectName(QString::fromUtf8("actionGuardar_Imagen_Como"));
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 190, 191, 171));
        btnSegStd = new QToolButton(groupBox_2);
        btnSegStd->setObjectName(QString::fromUtf8("btnSegStd"));
        btnSegStd->setGeometry(QRect(20, 30, 141, 28));
        btnSegLocal = new QToolButton(groupBox_2);
        btnSegLocal->setObjectName(QString::fromUtf8("btnSegLocal"));
        btnSegLocal->setGeometry(QRect(20, 80, 141, 28));
        btnSegWaterSheds = new QToolButton(groupBox_2);
        btnSegWaterSheds->setObjectName(QString::fromUtf8("btnSegWaterSheds"));
        btnSegWaterSheds->setGeometry(QRect(20, 130, 141, 28));
        btnSegLocal->raise();
        btnSegWaterSheds->raise();
        btnSegStd->raise();
        imgDisplay = new QGraphicsView(centralWidget);
        imgDisplay->setObjectName(QString::fromUtf8("imgDisplay"));
        imgDisplay->setGeometry(QRect(240, 10, 531, 501));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 191, 171));
        btnCannyFilter = new QToolButton(groupBox);
        btnCannyFilter->setObjectName(QString::fromUtf8("btnCannyFilter"));
        btnCannyFilter->setGeometry(QRect(20, 30, 141, 28));
        btnSobelFilter = new QToolButton(groupBox);
        btnSobelFilter->setObjectName(QString::fromUtf8("btnSobelFilter"));
        btnSobelFilter->setGeometry(QRect(20, 80, 141, 28));
        btnLoadDefImage = new QToolButton(centralWidget);
        btnLoadDefImage->setObjectName(QString::fromUtf8("btnLoadDefImage"));
        btnLoadDefImage->setGeometry(QRect(30, 400, 151, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 804, 25));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionAbrir_Imagen);
        menuArchivo->addAction(actionGuardar_Imagen);
        menuArchivo->addAction(actionGuardar_Imagen_Como);
        menuAyuda->addAction(actionSobre);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAbrir_Imagen->setText(QApplication::translate("MainWindow", "Abrir Imagen", 0, QApplication::UnicodeUTF8));
        actionGuardar_Imagen->setText(QApplication::translate("MainWindow", "Guardar Imagen", 0, QApplication::UnicodeUTF8));
        actionGuardar_Imagen_Como->setText(QApplication::translate("MainWindow", "Guardar Imagen Como...", 0, QApplication::UnicodeUTF8));
        actionSobre->setText(QApplication::translate("MainWindow", "Sobre...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Segmentacion", 0, QApplication::UnicodeUTF8));
        btnSegStd->setText(QApplication::translate("MainWindow", "Estandar", 0, QApplication::UnicodeUTF8));
        btnSegLocal->setText(QApplication::translate("MainWindow", "Local", 0, QApplication::UnicodeUTF8));
        btnSegWaterSheds->setText(QApplication::translate("MainWindow", "Watersheds", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Filtros", 0, QApplication::UnicodeUTF8));
        btnCannyFilter->setText(QApplication::translate("MainWindow", "Filtro de Canny", 0, QApplication::UnicodeUTF8));
        btnSobelFilter->setText(QApplication::translate("MainWindow", "Filtro de Sobel", 0, QApplication::UnicodeUTF8));
        btnLoadDefImage->setText(QApplication::translate("MainWindow", "Load Default Image", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
