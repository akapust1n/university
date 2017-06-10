QT       += core
QT       -= gui
QT += widgets

TARGET = studentPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += pluginStudent.h \ 
    SComand.h \
    ../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h
   
                          
SOURCES       += pluginStudent.cpp \ 
    SComand.cpp \
    ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp

DESTDIR       = ../
