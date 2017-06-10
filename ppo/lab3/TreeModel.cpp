#include "TreeModel.h"




//bool TreeModel::insertGroup(QString groupName)
//{
//    QVector<QVariant> groupData;
//    groupData << groupName;

//    TreeItem *root = rootItem->child(0);

//    bool result = root->insertChildren(root->childCount(), 1, 1);
//    for (int i = 0; i < groupData.size(); i++)
//        root->child(root->childCount() - 1)->setData(i, groupData[i]);

//    return result;
//}

//bool TreeModel::insertStudent(QStringList studentInfo, QString groupName)
//{
//    bool result;
//    TreeItem *root = rootItem->child(0);

//    QVector<QVariant> studentData;
//    foreach (QString buf, studentInfo) {
//        studentData << buf;
//    }

//    TreeItem *groupItem = Q_NULLPTR;

//    for (int i = 0; i < root->childCount(); i++) {
//        if (root->child(i)->data(0).toString() == groupName) {
//            result = true;
//            groupItem = root->child(i);
//        }
//    }

//    if (!groupItem) {
//        result = insertGroup(groupName);
//        groupItem = root->child(root->childCount() - 1);
//    }

//    if (!result) {
//        return result;
//    }

//    result = groupItem->insertChildren(groupItem->childCount(), 1, studentData.size());
//    for (int i = 0; i < studentInfo.size(); i++)
//        groupItem->child(groupItem->childCount() - 1)->setData(i, studentData[i]);
//}









TreeModel::TreeModel(const QStringList &headers, QObject *parent)
    : QAbstractItemModel(parent)
{
    //std::cout<<"start create TreeModel"<<std::endl;
    QVector<QVariant> rootData;
    foreach (QString header, headers)
        rootData << header;

    rootItem = new TreeItem(rootData);
    setupModelData(rootItem);
    //std::cout<<"end create Tree Model"<<std::endl;
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = getItem(index);

    return item->data(index.column());
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TreeItem *parentItem = getItem(parent);

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    TreeItem *buf = rootItem;
    int max = 0;
    while (buf->child(0)) {
        if (buf->columnCount() > max)
            max = buf->columnCount();
        buf = buf->child(0);
    }
    return max;
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    TreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}

bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

bool TreeModel::insertColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginInsertColumns(parent, position, position + columns - 1);
    success = rootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool TreeModel::removeColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginRemoveColumns(parent, position, position + columns - 1);
    success = rootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (rootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
    endInsertRows();

    return success;
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

TreeItem *TreeModel::getRootItem()
{
    return rootItem;
}

void TreeModel::setupModelData(TreeItem *parent)
{
    QVector<QVariant> data;
    data << "Groups";
    parent->insertChildren(0, 1, 1);
    parent->child(parent->childCount() - 1)->setData(0, data[0]);
}

TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}
