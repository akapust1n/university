QT += widgets

FORMS       = mainwindow.ui
HEADERS     = mainwindow.h \
              treemodel.h \
    DoManager.h \
    Comands.h \
    GroupItem.h \
    StudentItem.h
RESOURCES   =
SOURCES     = mainwindow.cpp \
              treemodel.cpp \
              main.cpp \
    DoManager.cpp \
    Comands.cpp \
    GroupItem.cpp \
    StudentItem.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/editabletreemodel
INSTALLS += target

DISTFILES +=
