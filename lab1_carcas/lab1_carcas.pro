#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T22:06:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab1_carcas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    interface.cpp \
    file_read.cpp \
    entrypoint.cpp \
    conversions.cpp \
    matrixworks.cpp \
    render.cpp \
    redraw.cpp \
    draw_lines.cpp

HEADERS  += mainwindow.h \
    file_read.h \
    entrypoint.h \
    conversions.h \
    matrixworks.h \
    canvasworks.h \
    render.h \
    redraw.h \
    draw_lines.h

FORMS    += mainwindow.ui
