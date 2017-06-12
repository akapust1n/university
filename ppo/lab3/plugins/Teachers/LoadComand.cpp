#include "LoadComand.h"

LoadTeachersCommand::LoadTeachersCommand(QString name, QTreeView* widget)
    : fileName(name)
{
    std::cout << "load comand created" << std::endl;
    treeView = widget;
    std::cout << "load comand created 2" << std::endl;
}

void LoadTeachersCommand::undo()
{
    delete treeModel;
}

void LoadTeachersCommand::redo()
{
    loadsubjectsFromJson(fileName);
    treeView->setModel(treeModel);
}

void LoadTeachersCommand::loadsubjectsFromJson(QString fileName)
{
    treeModel = loadFromJson(fileName);
}

TreeModel* LoadTeachersCommand::loadFromJson(QString fileName)
{
    std::cout << "loadFromJson start" << std::endl;
    std::cout << "FILENAME " << fileName.toStdString() << std::endl;
    QStringList headers;
    headers << "Teachers Info"
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

    loadTeachers(FileLoader, ret);
    FileLoader.close();
    return ret;
}

void LoadTeachersCommand::loadTeachers(QFile& FileLoader, TreeModel* _treeModel)
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
        std::cout << "error read  array file" << std::endl;
        return;
    }

    for (int i = 0; i < arr.size(); i++) {

        QJsonObject stud = arr[i].toObject();
        QStringList studentInfo = getStudentInfo(stud);
        QString subjectName = stud["Subject"].toString();
        //treeModel->insertStudent(studentInfo, subjectName);
        insertTeachersToModel(studentInfo, subjectName, _treeModel);
    }
}

QStringList LoadTeachersCommand::getStudentInfo(QJsonObject& json)
{
    QStringList ret;

    QString surName(json["Surname"].toString());
    QString name(json["Name"].toString());
    QString secondName(json["SecondName"].toString());

    ret << surName << name << secondName;

    return ret;
}

void LoadTeachersCommand::insertTeachersToModel(QStringList studentInfo, QString subjectName, TreeModel* _treeModel)
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

    TreeItem* subjectItem = Q_NULLPTR;

    for (int i = 0; i < root->childCount(); i++) {

        if (root->child(i)->data(0).toString() == subjectName) {
            result = true;
            subjectItem = root->child(i);
        }
    }

    if (!subjectItem) {
        result = insertsubject(subjectName,_treeModel);
        subjectItem = root->child(root->childCount() - 1);
    }

    std::cout << "insertStudentToModel phase6" << std::endl;

    result = subjectItem->insertChildren(subjectItem->childCount(), 1, studentData.size());
    for (int i = 0; i < studentInfo.size(); i++)
        subjectItem->child(subjectItem->childCount() - 1)->setData(i, studentData[i]);
}

bool LoadTeachersCommand::insertsubject(QString subjectName, TreeModel *_treeModel)
{
    QVector<QVariant> subjectData;
    subjectData << subjectName;
     std::cout<<"insert subject phase1"<<std::endl;
    TreeItem* root = _treeModel->getRootItem()->child(0);

    bool result = root->insertChildren(root->childCount(), 1, 1);
    for (int i = 0; i < subjectData.size(); i++)
        root->child(root->childCount() - 1)->setData(i, subjectData[i]);

    return result;
}

TreeModel *LoadTeachersCommand::getTreeModel()
{
    return treeModel;
}
