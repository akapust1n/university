#include "groupinfo.h"
#include <iostream>

GroupInfo::GroupInfo(QAbstractItemModel* _model)
{
    model = dynamic_cast<TreeModel*>(_model);
}

QString GroupInfo::getGroupInfo(QString group)
{
    std::cout << "getGroupInfo" << group.toStdString() << std::endl;
    QString result;
    double avgRating = 0;
    double maxRating = 0;
    double minRating = 100;
    TreeItem* item = model->rootItem;
    TreeItem* groupItem;
    int count = model->rootItem->childCount();
    std::cout << "COUNT " << count << std::endl;
    for (int i = 0; i < model->rootItem->childCount(); i++) {
        std::cout << "INTO GROUP ITER " << item->child(i)->data(1).toString().toStdString() << std::endl;
        if (item->child(i)->data(1).toString() == group) {

            groupItem = item->child(i);
            break;
        }
    }
    std::cout << "AFTER ITER" << std::endl;
    std::cout << "child count groupIten" << groupItem->childCount() << std::endl;
    for (int i = 0; i < groupItem->childCount(); i++) {
        int rating = groupItem->child(i)->child(2)->data(1).toInt();
        if (maxRating < rating)
            maxRating = rating;
        if (minRating > rating)
            minRating = rating;
        avgRating += rating;
    }
    avgRating /= groupItem->childCount();
    result += " Количество студентов: " + QString::number(groupItem->childCount()) + "\n";
    result += " Максимальный рейтинг: " + QString::number(maxRating) + "\n";
    result += " Минимальный рейтинг: " + QString::number(minRating) + "\n";
    result += " Средний рейтинг: " + QString::number(avgRating) + "\n";

    std::cout << "END GROUP INFO" << std::endl;
    return result;
}

QJsonArray GroupInfo::getArray(QString group)
{
    TreeItem* item = model->rootItem;
    for (int i = 0; i < model->rootItem->childCount(); i++) {
        TreeItem *groupItem = item->child(i);


    }
}
