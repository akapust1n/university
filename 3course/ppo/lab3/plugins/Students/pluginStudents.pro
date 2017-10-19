QT       += core
QT       -= gui
QT += widgets
CONFIG +=c++14
TARGET = studentPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += pluginStudent.h \ 
    ../../TreeModel.h \
    ../../TreeItem.h \
    ../../Comands.h \
    LoadComand.h \
    RemoveComand.h \
    InsertComand.h \
    InsertGroup.h \
    InsertStudent.h \
    ChangeComand.h \
    ChangeGroup.h \
    ChangeStudent.h
   
                          
SOURCES       += pluginStudent.cpp \ 
    ../../TreeModel.cpp \
    ../../TreeItem.cpp \
    ../../Comands.cpp \
    LoadComand.cpp \
    RemoveComand.cpp \
    InsertComand.cpp \
    InsertGroup.cpp \
    InsertStudent.cpp \
    ChangeComand.cpp \
    ChangeGroup.cpp \
    ChangeStudent.cpp
FORMS    +=  insertgroup.ui \
        insertstudent.ui \
    changegroup.ui \
    changestudent.ui
DESTDIR       = ../

DISTFILES += \
    .qmake.stash

