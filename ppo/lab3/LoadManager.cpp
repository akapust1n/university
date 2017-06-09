#include "LoadManager.h"
#include "Loader.h"


LoadManager::~LoadManager()
{
    delete this->m_loader;
}

TreeModel *LoadManager::loadFromJson(QString &fileName)
{
    this->m_loader = new JsonFileLoader();
    QStringList headers;
    headers << "Groups Info" << "" << "" << "" << "";
    TreeModel *ret = new TreeModel(headers);
    this->m_loader->Load(ret, fileName);
    return ret;
}
