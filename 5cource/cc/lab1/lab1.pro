CONFIG -= qt
CONFIG += c++1z console

LIBS += -lgtest -lgvc -lcgraph

SOURCES += \
        main.cpp \
    DKA.cpp \
    State.cpp \
    Automatia.cpp

HEADERS += \
    DKA.h \
    State.h \
    Automatia.h
