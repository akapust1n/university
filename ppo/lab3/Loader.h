#ifndef LOADER_H
#define LOADER_H

#include <QFile>
#include <QJsonObject>
#include <TreeModel.h>

class BaseLoaderImpl;
class BaseLoader
{
public:
    BaseLoader(BaseLoaderImpl* ld) : ldImpl(ld){}
    virtual ~BaseLoader()
    {
        delete ldImpl;
    }

    virtual bool Load(TreeModel *Unit, QString &Name) = 0;
protected:
    BaseLoaderImpl* ldImpl;
};

class BaseLoaderImpl
{
public:
    virtual ~BaseLoaderImpl(){}
    virtual bool Load(TreeModel *Unit, QString &Name) = 0;
};


class JsonFileLoaderImpl : public BaseLoaderImpl
{
public:
    bool Load(TreeModel *Unit,QString &Name);
private:
    void openFile(QFile &FileLoader, QString &Name);

    QStringList getStudentInfo(QJsonObject &json);
    void loadStrudents(QFile &FileLoader, TreeModel *Unit);

    void closeFile(QFile &FileLoader);
};

class JsonFileLoader : public BaseLoader
{
public:
    JsonFileLoader();
    bool Load(TreeModel *Unit, QString &Name);
};

class Loader
{
public:
    Loader();
};

#endif // LOADER_H
