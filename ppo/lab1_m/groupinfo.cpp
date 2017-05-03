#include "groupinfo.h"
#include <iostream>

GroupInfo::GroupInfo(QAbstractItemModel *_model)
{
    model = dynamic_cast<TreeModel*>(_model);

}

QString GroupInfo::getGroupInfo(QString group)
{
    std::cout<<"GROUP "<<group.toStdString()<<std::endl;
    int numStudent;
    double avgRating=0;
    double maxRating=0;
    double minRating=0;
TreeItem *item = model->rootItem;
TreeItem *groupItem;
for(int i=0;i<model->rootItem->childCount();i++){
if (item->child(i)->data(1).toString() == group){
    groupItem = item->child(i);
    break;
}
}
for(int i=0;groupItem->childCount();i++){
    std::cout<<groupItem->child(i)->child(3)->data(0).toString().toStdString()<<std::endl;

}



}
