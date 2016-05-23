#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T12:56:52
#
#-------------------------------------------------

QT       += 3dcore 3drender 3dinput 3dlogic

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = printr
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    viewer.cpp \
    transformer.cpp \
    cameraholder.cpp

HEADERS  += \
    mainwindow.hpp \
    viewer.hpp \
    transformer.hpp \
    cameraholder.hpp

DISTFILES +=
