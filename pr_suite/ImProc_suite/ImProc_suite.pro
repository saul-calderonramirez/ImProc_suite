#-------------------------------------------------
#
# Project created by QtCreator 2013-03-14T21:16:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImProc_suite
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imageimpro.cpp \
    openimprolib.cpp \
    openimprolib_opencvimpl.cpp \
    imageimpro_opencvimpl.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    imageimpro.h \
    openimprolib.h \
    openimprolib_opencvimpl.h \
    imageimpro_opencvimpl.h \
    controller.h

FORMS    += mainwindow.ui
#We add the packages of open Cv to the compiler and the linker
CONFIG += link_pkgconfig
PKGCONFIG += opencv
