QT       += core
QT       -= gui
QT += widgets

TARGET = exporteSelectedPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       +=     exportSelectedPlugin.h \
../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h \      
    exportComand.h \
    SaveFileAs.h
   

SOURCES       +=      exportSelectedPlugin.cpp \
 ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp \
    exportComand.cpp \
    SaveFileAs.cpp




DESTDIR       = ../

FORMS += \
    saveFile.ui \
    saveFile.ui



