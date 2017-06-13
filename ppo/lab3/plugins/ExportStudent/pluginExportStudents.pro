QT       += core
QT       -= gui
QT += widgets

CONFIG +=c++14

TARGET = studentExportPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += pluginExportStudent.h \ 
    ../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h \      
    ExportStudentComand.h \
    SaveFileAs.h

SOURCES       += pluginExportStudent.cpp \  
    ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp \
    ExportStudentComand.cpp \
    SaveFileAs.cpp 



DESTDIR       = ../

FORMS += \
    saveFile.ui



