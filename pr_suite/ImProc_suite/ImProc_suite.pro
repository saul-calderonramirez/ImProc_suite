#-------------------------------------------------
#
# Project created by QtCreator 2013-03-14T21:16:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImProc_suite
TEMPLATE = app
LIBS += -L/usr/local/lib -lfann
SOURCES += main.cpp\
    imageimpro.cpp \
    openimprolib.cpp \
    openimprolib_opencvimpl.cpp \
    imageimpro_opencvimpl.cpp \
    controller.cpp \
    mainwindow.cpp \
    openimprolib_opencvoclimpl.cpp \
    openimprolib_opencvgpuimpl.cpp \
    unittests.cpp \
    hogdetectorgpu.cpp \
    stdafx.cpp \
    svmlight.cpp \
    qcustomplot.cpp \
    neuralnet.cpp


HEADERS  += \
    imageimpro.h \
    openimprolib.h \
    openimprolib_opencvimpl.h \
    imageimpro_opencvimpl.h \
    controller.h \
    mainwindow.h \
    includes.h \
    openimprolib_opencvoclimpl.h \
    openimprolib_opencvgpuimpl.h \
    unittests.h \
    hogdetectorgpu.h \
    stdafx.h \
    svmlight.h \
    qcustomplot.h \
    neuralnet.h

FORMS    += \
    mainwindow.ui
#We add the packages of open Cv to the compiler and the linker
CONFIG += link_pkgconfig
PKGCONFIG += opencv


