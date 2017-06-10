#include "LoadComand.h"

LoadStudentsCommand::LoadStudentsCommand(QString name, QTreeView* widget)
    : fileName(name)
{
    std::cout << "load comand created" << std::endl;
    treeView = widget;
    std::cout << "load comand created 2" << std::endl;
}

void LoadStudentsCommand::undo()
{
    delete treeModel;
}

void LoadStudentsCommand::redo()
{
    loadGroupsFromJson(fileName);
    treeView->setModel(treeModel);
}

void LoadStudentsCommand::loadGroupsFromJson(QString fileName)
{
    treeModel = loadFromJson(fileName);
}

TreeModel* LoadStudentsCommand::loadFromJson(QString fileName)
{
    std::cout << "loadFromJson start" << std::endl;
    std::cout << "FILENAME " << fileName.toStdString() << std::endl;
    QStringList headers;
    headers << "Groups Info"
            << ""
            << ""
            << ""
            << "";
    std::cout << "before new TreeModel create" << std::endl;

    TreeModel* ret = new TreeModel(headers);
    std::cout << "after new TreeModel create" << std::endl;
    //load File
    QFile FileLoader;

    FileLoader.setFileName(fileName);

    if (!FileLoader.open(QIODevice::ReadOnly)) {
        std::cout << "error open file" << std::endl;
        return nullptr;
    }
    std::cout << "befor load student" << std::endl;

    loadStudents(FileLoader, ret);
    // closeFile(tmp);
    return ret;
}

void LoadStudentsCommand::loadStudents(QFile& FileLoader, TreeModel* _treeModel)
{
    std::cout << "loadStudents phase1" << std::endl;
    QByteArray loadData = FileLoader.readAll();
    if (loadData.isEmpty()) {
        std::cout << "error read file" << std::endl;
        return;
    }
    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    std::cout << "loadStudents phase2" << std::endl;

    QJsonArray arr = loadDoc.array();
    arr.toVariantList();
    if (arr.isEmpty()) {
        std::cout << "error read file" << std::endl;
        return;
    }
    std::cout << "loadStudents phase3" << std::endl;

    for (int i = 0; i < arr.size(); i++) {
        std::cout << "loadStudents phase4" << std::endl;

        QJsonObject stud = arr[i].toObject();
        QStringList studentInfo = getStudentInfo(stud);
        QString groupName = stud["Group"].toString();
        //treeModel->insertStudent(studentInfo, groupName);
        insertStudentToModel(studentInfo, groupName, _treeModel);
    }
}

QStringList LoadStudentsCommand::getStudentInfo(QJsonObject& json)
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

void LoadStudentsCommand::insertStudentToModel(QStringList studentInfo, QString groupName, TreeModel* _treeModel)
{
    bool result;
    std::cout << "insertStudentToModel phase1" << std::endl;
    TreeItem* root = _treeModel->getRootItem()->child(0);

    QVector<QVariant> studentData;
    foreach (QString buf, studentInfo) {
        studentData << buf;
    }
    std::cout << "insertStudentToModel phase2" << std::endl;
    std::cout << "root phase2" << root << std::endl;
    std::cout << root->childCount() << std::endl;

    TreeItem* groupItem = Q_NULLPTR;

    for (int i = 0; i < root->childCount(); i++) {
        std::cout << "insertStudentToModel phase3" << std::endl;

        if (root->child(i)->data(0).toString() == groupName) {
            result = true;
            groupItem = root->child(i);
            std::cout << "insertStudentToModel phase 3.5" << std::endl;
        }
        std::cout << "insertStudentToModel phase4" << std::endl;
    }
    std::cout << "insertStudentToModel phase5" << std::endl;

    if (!groupItem) {
        result = insertGroup(groupName,_treeModel);
        groupItem = root->child(root->childCount() - 1);
    }

    std::cout << "insertStudentToModel phase6" << std::endl;

    result = groupItem->insertChildren(groupItem->childCount(), 1, studentData.size());
    for (int i = 0; i < studentInfo.size(); i++)
        groupItem->child(groupItem->childCount() - 1)->setData(i, studentData[i]);
}

bool LoadStudentsCommand::insertGroup(QString groupName, TreeModel *_treeModel)
{
    QVector<QVariant> groupData;
    groupData << groupName;
     std::cout<<"insert group phase1"<<std::endl;
    TreeItem* root = _treeModel->getRootItem()->child(0);

    bool result = root->insertChildren(root->childCount(), 1, 1);
    for (int i = 0; i < groupData.size(); i++)
        root->child(root->childCount() - 1)->setData(i, groupData[i]);

    return result;
}

TreeModel *LoadStudentsCommand::getTreeModel()
{
    return treeModel;
}
