QT       += core
QT       -= gui
QT += widgets

TARGET = starostaPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += \ 
    ../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h \
    SComand.h \
    pluginStarosta.h
   
                          
SOURCES       += \ 
    ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp \
    SComand.cpp \
    pluginStarosta.cpp
FORMS    += 
DESTDIR       = ../

DISTFILES += \
    .qmake.stash

