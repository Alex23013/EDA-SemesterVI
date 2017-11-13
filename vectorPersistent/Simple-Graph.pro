QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simple-Graph
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++14

SOURCES += \
    main.cpp \
    qtGraphics/graphScene.cpp \
    qtGraphics/mainWindow.cpp \
    cnode.cpp \
    cbinarytree.cpp \
    cnodegraphic.cpp \
    cfatnodes.cpp

HEADERS += \
    qtGraphics/graphScene.h \
    qtGraphics/mainWindow.h \
    cnode.h \
    cbinarytree.h \
    cnodegraphic.h \
    cfatnodes.h

# FORMS += 
