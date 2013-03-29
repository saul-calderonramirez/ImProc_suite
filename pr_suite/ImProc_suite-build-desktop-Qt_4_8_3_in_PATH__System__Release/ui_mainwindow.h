/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 29 10:54:19 2013
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
    QToolButton *btnSegWaterSheds;
    QToolButton *btnLoadDefImage;
    QGroupBox *groupBox;
    QToolButton *btnCannyFilter;
    QToolButton *btnSobelFilter;
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
        groupBox_2->setGeometry(QRect(30, 200, 191, 171));
        btnUmbBin = new QToolButton(groupBox_2);
        btnUmbBin->setObjectName(QString::fromUtf8("btnUmbBin"));
        btnUmbBin->setGeometry(QRect(20, 30, 141, 31));
        btnSegLocal = new QToolButton(groupBox_2);
        btnSegLocal->setObjectName(QString::fromUtf8("btnSegLocal"));
        btnSegLocal->setGeometry(QRect(20, 80, 141, 28));
        btnSegWaterSheds = new QToolButton(groupBox_2);
        btnSegWaterSheds->setObjectName(QString::fromUtf8("btnSegWaterSheds"));
        btnSegWaterSheds->setGeometry(QRect(20, 130, 141, 28));
        btnSegLocal->raise();
        btnSegWaterSheds->raise();
        btnUmbBin->raise();
        btnLoadDefImage = new QToolButton(centralwidget);
        btnLoadDefImage->setObjectName(QString::fromUtf8("btnLoadDefImage"));
        btnLoadDefImage->setGeometry(QRect(50, 410, 151, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 191, 171));
        btnCannyFilter = new QToolButton(groupBox);
        btnCannyFilter->setObjectName(QString::fromUtf8("btnCannyFilter"));
        btnCannyFilter->setGeometry(QRect(20, 30, 141, 28));
        btnSobelFilter = new QToolButton(groupBox);
        btnSobelFilter->setObjectName(QString::fromUtf8("btnSobelFilter"));
        btnSobelFilter->setGeometry(QRect(20, 80, 141, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        btnSegWaterSheds->setText(QApplication::translate("MainWindow", "Watersheds", 0, QApplication::UnicodeUTF8));
        btnLoadDefImage->setText(QApplication::translate("MainWindow", "Load Default Image", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Filtros", 0, QApplication::UnicodeUTF8));
        btnCannyFilter->setText(QApplication::translate("MainWindow", "Filtro de Canny", 0, QApplication::UnicodeUTF8));
        btnSobelFilter->setText(QApplication::translate("MainWindow", "Filtro de Sobel", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
