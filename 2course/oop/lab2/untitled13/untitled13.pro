QT += core
QT -= gui

CONFIG += c++11

TARGET = untitled13
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    my_map.h \
    iterator.h \
    base.h \
    my_exception.h \
    my_map_realis.h \
    base_realis.h \
    dict.h \
    dict_realis.h
