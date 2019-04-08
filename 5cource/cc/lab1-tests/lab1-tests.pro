CONFIG -= qt
CONFIG += c++1z console

LIBS += -lgtest -lpthread -lgvc -lcgraph


SOURCES += \
        main.cpp \
    tests.cpp \
    ../lab1/Automatia.cpp \
    ../lab1/State.cpp \
    ../lab1/DKA.cpp

