#include "Loader.h"

//#include "jsonloader.h"

//#include "Errors/load_error.h"
#include "Error.h"
#include <QJsonDocument>
#include <QJsonArray>

bool JsonFileLoaderImpl::Load(TreeModel *Unit, QString &Name)
{
    try
    {
        QFile tmp;

        openFile(tmp, Name);
        loadStrudents(tmp, Unit);
        closeFile(tmp);
    }
    catch(BaseError& er)
    {
        return false;
    }

    return true;
}

void JsonFileLoaderImpl::openFile(QFile &FileLoader, QString &Name)
{
    FileLoader.setFileName(Name);

    if (!FileLoader.open(QIODevice::ReadOnly))
        throw OpenError();
}

QStringList JsonFileLoaderImpl::getStudentInfo(QJsonObject &json)
{
    QStringList ret;

    QString surName(json["Surname"].toString());
    QString name(json["Name"].toString());
    QString secondName(json["SecondName"].toString());
    QString raiting = QString::number(json["Rating"].toInt());
    QString role = json["Role"].toString();

    ret << surName << name << secondName << raiting << role;

    return ret;
}

void JsonFileLoaderImpl::loadStrudents(QFile &FileLoader, TreeModel *Unit)
{
    QByteArray loadData = FileLoader.readAll();
    if (loadData.isEmpty())
        throw FileError();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));

    QJsonArray arr = loadDoc.array();
    arr.toVariantList();
    if (arr.isEmpty())
        throw FileError();

    for (int i = 0; i < arr.size(); i++) {
        QJsonObject stud = arr[i].toObject();
        QStringList studentInfo = getStudentInfo(stud);
        QString groupName = stud["Group"].toString();

        Unit->insertStudent(studentInfo, groupName);
    }
}

void JsonFileLoaderImpl::closeFile(QFile &FileLoader)
{
    FileLoader.close();
}

JsonFileLoader::JsonFileLoader() : BaseLoader(new JsonFileLoaderImpl){}

bool JsonFileLoader::Load(TreeModel *Unit, QString &Name)
{
    return this->ldImpl->Load(Unit, Name);
}
