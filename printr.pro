#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T12:56:52
#
#-------------------------------------------------

CONFIG += c++11
QT       += 3dcore 3drender 3dinput 3dlogic

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = printr
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    cameraholder.cpp \
    mainwidget.cpp \
    previewwidget.cpp \
    presenter.cpp \
    sceneview.cpp \
    model.cpp

HEADERS  += \
    mainwindow.hpp \
    cameraholder.hpp \
    mainwidget.hpp \
    previewwidget.hpp \
    presenter.hpp \
    sceneview.hpp \
    model.hpp

DISTFILES +=
