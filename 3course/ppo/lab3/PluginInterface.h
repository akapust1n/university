#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H


#include <QString>
#include <QVariant>
#include <QVector>
#include <QModelIndex>
#include "TreeModel.h"
class MainWindow;
class PluginAbstruct
{
public:
    virtual ~PluginAbstruct() {}

    virtual QVariant doThing(MainWindow *_th) = 0;
    MainWindow *th;
};


#define PluginAbstruct_id "ru.lab3.PluginAbstruct"

Q_DECLARE_INTERFACE(PluginAbstruct, PluginAbstruct_id)



#endif // PLUGININTERFACE_H
