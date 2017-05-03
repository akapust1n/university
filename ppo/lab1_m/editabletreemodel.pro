QT += widgets

FORMS       = mainwindow.ui
HEADERS     = mainwindow.h \
              treemodel.h \
    Comands.h \
    treeitem.h \
    groupinfo.h
RESOURCES   =
SOURCES     = mainwindow.cpp \
              treemodel.cpp \
              main.cpp \
    treeitem.cpp \
    groupinfo.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/editabletreemodel
INSTALLS += target

DISTFILES +=
