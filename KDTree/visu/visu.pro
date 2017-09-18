#-------------------------------------------------
#
# Project created by QtCreator 2017-09-17T10:33:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Coordinate.cpp \
    KDTree.cpp \
    Node.cpp

HEADERS  += mainwindow.h \
    Coordinate.h \
    csvLector.h \
    KDTree.h \
    Node.h \
    radix.h

FORMS    += mainwindow.ui
