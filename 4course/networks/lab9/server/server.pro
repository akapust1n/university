CONFIG += c++14
CONFIG -=qt
QT     -= gui core
LIBS   -= -lQtGui -lQtCoreq
unix|win32: LIBS += -lzdb

CONFIG += qt debug
SOURCES += \
    client.c \
    logger.c \
    main.c \
    cyclobuffer.c

HEADERS += \
    client.h \
    logger.h \
    cyclobuffer.h \
    structs.h