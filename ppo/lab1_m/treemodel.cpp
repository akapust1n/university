#include <QtWidgets>

#include "StudentItem.h"
#include "treemodel.h"
#include <iostream>

TreeModel::TreeModel(const QStringList &headers, const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    foreach (QString header, headers)
        rootData << header;


    QJsonDocument document =QJsonDocument::fromJson(data.toUtf8());
    QJsonArray array = document.array();
    setupModelData(array);
}

TreeModel::~TreeModel()
{
    for(auto &temp:parents){
        delete  temp;
    };
}

int TreeModel::columnCount(const QModelIndex & /* parent */) const
{
    //return rootItem->columnCount();
}

bool TreeModel::hasChildren(const QModelIndex &parent) const
{

}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid())
//        return QVariant();

//    if (role != Qt::DisplayRole && role != Qt::EditRole)
//        return QVariant();

//    StudentItem *item = getItem(index);

//    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

StudentItem *TreeModel::getItem(const QModelIndex &index) const
{
//    if (index.isValid()) {
//        StudentItem *item = static_cast<StudentItem*>(index.internalPointer());
//        if (item)
//            return item;
//    }
//   // return rootItem;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
//    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
//       // return rootItem->data(section);

//    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
//    if (parent.isValid() && parent.column() != 0)
//        return QModelIndex();

//    StudentItem *parentItem = getItem(parent);

//    StudentItem *childItem = parentItem->child(row);
//    if (childItem)
//        return createIndex(row, column, childItem);
//    else
//        return QModelIndex();
}


bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
//    StudentItem *parentItem = getItem(parent);
//    bool success;

//    beginInsertRows(parent, position, position + rows - 1);
//    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
//    endInsertRows();

//    return success;
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
//    if (!index.isValid())
//        return QModelIndex();

//    StudentItem *childItem = getItem(index);
//    StudentItem *parentItem = childItem->parent();

//    if (parentItem == rootItem)
//        return QModelIndex();

//    return createIndex(parentItem->childNumber(), 0, parentItem);
}



bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
//    StudentItem *parentItem = getItem(parent);
//    bool success = true;

//    beginRemoveRows(parent, position, position + rows - 1);
//    success = parentItem->removeChildren(position, rows);
//    endRemoveRows();

//    return success;
}

GroupItem *TreeModel::findGroup(QString group, int &number)
{
    for(auto &temp:parents)
    {
        if(temp->getGroup() == group)
            return  temp;
    }
    GroupItem *newItem = new GroupItem(number);
    number++;
    parents.append(newItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
//    StudentItem *parentItem = getItem(parent);

//    return parentItem->childCount();
    return  0;
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    StudentItem *item = getItem(index);
    bool result = true;//item->setData(index.column(), value);
    std::cout<<"data changed"<<std::endl;;
    std::cout<<value.toString().toStdString()<<std::endl;

    if (result)
        emit dataChanged(index, index);

    return result;
}



void TreeModel::setupModelData(const QJsonArray &array)
{
   int number = 1;
    foreach (const QJsonValue & value, array) {
        QJsonObject obj = value.toObject();
        StudentItem::Student student;

        QString group =  obj["Group"].toString();
        auto groupItem = findGroup(group, number);
        student.name =  obj["Name"].toString();
        student.secondName = obj["SecondName"].toString();
        student.rating = obj["Rating"].toInt();
        student.role = obj["Role"].toString();
        //groupItem->insertChildren()

    }
//            TreeItem *parent = parents.last();
//            parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
//            for (int column = 0; column < columnData.size(); ++column)
//                parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
//        }


}
