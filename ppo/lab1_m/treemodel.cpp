#include "treemodel.h"
#include "treeitem.h"
#include <QtWidgets>
#include <iostream>

TreeModel::TreeModel()
{
    QVector<QVariant> rootData;
    rootData << "header";

    rootItem = new TreeItem(rootData);
    QString temp("data");
    setupModelData(temp, rootItem);
}

TreeModel::TreeModel(const QStringList& headers, const QString& data, QObject* parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    foreach (QString header, headers)

        rootItem = new TreeItem(rootData);
    setupModelData(data, rootItem);
}

TreeModel* TreeModel::getCopy()
{
    std::cout << "copy CALLED" << std::endl;

    TreeModel* obj = new TreeModel;
    QVector<QVariant> rootData;
    rootData << "header";

    obj->rootItem = new TreeItem(rootData);
    int tt = rootItem->childCount();
    int tt2 = rootItem->child(0)->childCount();
    for (int i = 0; i < rootItem->childCount(); i++) {
        obj->rootItem->insertChildren(i, 1, rootItem->columnCount());
        obj->rootItem->child(i)->setData(1, rootItem->child(i)->data(1));
        std::cout << "GROUPs" << rootItem->child(i)->data(1).toString().toStdString() << std::endl;

        TreeItem* group = rootItem->child(i);
        for (int j = 0; j < group->childCount(); j++) {
            obj->rootItem->child(i)->insertChildren(j, 1, rootItem->columnCount());
            obj->rootItem->child(i)->child(j)->setData(1, group->child(j)->data(1));
            TreeItem* man = group->child(j);

            for (int k = 0; k < man->childCount(); k++) {
                obj->rootItem->child(i)->child(j)->insertChildren(k, 1, rootItem->columnCount());
                obj->rootItem->child(i)->child(j)->child(k)->setData(1, man->child(k)->data(1));
            }
        }
    }
    return obj;
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

int TreeModel::columnCount(const QModelIndex& /* parent */) const
{
    return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem* item = getItem(index);

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

TreeItem* TreeModel::getItem(const QModelIndex& index) const
{
    if (index.isValid()) {
        TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex& parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TreeItem* parentItem = getItem(parent);

    TreeItem* childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex& parent)
{
    TreeItem* parentItem = getItem(parent);
    bool success;
    if (parentItem->parent())
        if (parentItem->parent()->parent())
            if (parentItem->parent()->parent()->parent())
                //if(parentItem->parent()->parent()->parent()->parent())
                return false;
    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
    endInsertRows();

    return success;
}

QModelIndex TreeModel::parent(const QModelIndex& index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem* childItem = getItem(index);
    TreeItem* parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex& parent)
{
    TreeItem* parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

TreeItem* TreeModel::findGroup(QString group)
{
    for (int i = 0; i < rootItem->childCount(); i++) {
        if (rootItem->child(i)->data(1).toString() == group)
            return rootItem->child(i);
    }
    rootItem->insertChildren(rootItem->childCount(), 1, rootItem->columnCount());
    rootItem->child(rootItem->childCount() - 1)->setData(1, QVariant(group));
    return rootItem->child(rootItem->childCount() - 1);
}

int TreeModel::rowCount(const QModelIndex& parent) const
{
    TreeItem* parentItem = getItem(parent);

    return parentItem->childCount();
}

bool TreeModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role != Qt::EditRole)
        return false;

    TreeItem* item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}

bool TreeModel::setHeaderData(int section, Qt::Orientation orientation,
    const QVariant& value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

void TreeModel::setupModelData(const QString& lines, TreeItem* parent)
{
    //  QList<TreeItem*> parents;
    //  parents << parent;
    QJsonDocument document = QJsonDocument::fromJson(lines.toUtf8());

    QJsonArray array = document.array();
    foreach (const QJsonValue& value, array) {
        QJsonObject obj = value.toObject();
        QString group = obj["Group"].toString();
        QString surname = obj["Surname"].toString();

        TreeItem* groupItem = findGroup(group);
        groupItem->insertChildren(groupItem->childCount(), 1, rootItem->columnCount());
        groupItem->child(groupItem->childCount() - 1)->setData(1, QVariant(surname));

        TreeItem* man = groupItem->child(groupItem->childCount() - 1);
        //тут было SetData(1
        man->insertChildren(man->childCount(), 1, rootItem->columnCount());
        man->child(man->childCount() - 1)->setData(1, QVariant(obj["Name"].toString()));
        man->insertChildren(man->childCount(), 1, rootItem->columnCount());
        man->child(man->childCount() - 1)->setData(1, QVariant(obj["SecondName"].toString()));
        man->insertChildren(man->childCount(), 1, rootItem->columnCount());
        man->child(man->childCount() - 1)->setData(1, QVariant(obj["Rating"].toInt()));
        man->insertChildren(man->childCount(), 1, rootItem->columnCount());
        man->child(man->childCount() - 1)->setData(1, QVariant(obj["Role"].toString()));
    }
}
