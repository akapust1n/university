QT       += core
QT       -= gui
QT += widgets

TARGET = studentPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += pluginStudent.h \ 
    ../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h \
    LoadComand.h \
    RemoveComand.h
   
                          
SOURCES       += pluginStudent.cpp \ 
    ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp \
    LoadComand.cpp \
    RemoveComand.cpp

DESTDIR       = ../
