#ifndef LOADMANAGER_H
#define LOADMANAGER_H
#include "TreeModel.h"
#include <QStringList>
#include "Loader.h"

class LoadManager
{
public:
    LoadManager(){}
    ~LoadManager();

    TreeModel *loadFromJson(QString &fileName);

private:
    BaseLoader *m_loader;
};
#endif // LOADMANAGER_H
