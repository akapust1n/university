QT       += core
QT       -= gui
QT += widgets

TARGET = teachersPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += \ 
    ../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h \
    LoadComand.h \
    pluginTeacher.h
   
                          
SOURCES       += \ 
    ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp \
    LoadComand.cpp \
    pluginTeacher.cpp
FORMS    += 
DESTDIR       = ../

DISTFILES += \
    .qmake.stash

