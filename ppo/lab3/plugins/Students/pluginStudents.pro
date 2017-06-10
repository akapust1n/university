QT       += core
QT       -= gui
QT += widgets

TARGET = studentPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH  += ../../
HEADERS       += pluginStudent.h
SOURCES       += pluginStudent.cpp

#DESTDIR       = ../../plugins
