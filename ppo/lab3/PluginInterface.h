#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H


#include <QString>
#include <QVariant>
#include <QVector>
#include <QModelIndex>
#include "TreeModel.h"

class PluginAbstruct
{
public:
    virtual ~PluginAbstruct) {}

    virtual QString getText() = 0;

    virtual QVariant doThing(QModelIndex indx, TreeModel *Unit) = 0;
//    virtual void exportInfo(QModelIndex indx, QString fileName, TreeModel *Unit) = 0;
};

//class InfoInterface
//{
//public:
//    virtual ~InfoInterface() {}

//    virtual QString getText() = 0;

//    virtual qreal groupStatistic(QModelIndex indx, TreeModel *Unit) = 0;
//};

#define ExportInterface_iid "ru.labs.GroupTree.ExportInterface/1.0"

Q_DECLARE_INTERFACE(PluginAbstruct, ExportInterface_iid)

//#define InfoInterface_iid "ru.labs.GroupTree.InfoInterface/1.0"

//Q_DECLARE_INTERFACE(InfoInterface, InfoInterface_iid)


#endif // PLUGININTERFACE_H
