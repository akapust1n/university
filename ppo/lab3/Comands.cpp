#include <Comands.h>
#include <iostream>



//SaveCommand::SaveCommand(QString name):
//    fileName(name)

//{
//}

//void SaveCommand::undo()
//{
//    QFile file(fileName);
//    file.remove();
//}

//void SaveCommand::redo()
//{
//    //comandManager->saveGroupsToJson(fileName);
//}

//ChangeInfoCommand::ChangeInfoCommand(QModelIndexList _indxList, QVector<QVariant> _nextData)
//    :
//    indxList(_indxList)
//    , nextData(_nextData)
//{
//    for (QModelIndex& indx : indxList) {
//        prevData << indx.data().toString();
//    }
//}

//ChangeInfoCommand::~ChangeInfoCommand() {}

//void ChangeInfoCommand::undo()
//{
//    //comandManager->changeInfo(indxList, prevData);
//}

//void ChangeInfoCommand::redo()
//{
//    //comandManager->changeInfo(indxList, nextData);
//}

//InsertCommand::InsertCommand(QModelIndex parent, QVector<QVariant> insertData)
//    : parent(parent)
//    , insertData(insertData)
//{
//}

//InsertCommand::~InsertCommand() {}

//void InsertCommand::undo()
//{
//    int row = -1;
//    do {
//        row++;
//    } while (parent.child(row + 1, 0).isValid());
//    //comandManager->deleteInfo(parent.child(row, 0));
//}

//void InsertCommand::redo()
//{
//    //comandManager->insertInfo(parent, insertData);
//}

//SaveCommand::~SaveCommand() {}

//RemoveCommand::RemoveCommand(QModelIndex indx, QVector<QVector<QVariant> > backData)
//    : index(indx)
//    , data(backData)
//    , parent(indx.parent())
//{
//}

//RemoveCommand::~RemoveCommand() {}

//void RemoveCommand::undo()
//{
//    //comandManager->insertInfo(parent, data.first());

//    int row = 0;
//    while (parent.child(row, 0).isValid()) {
//        index = parent.child(row, 0);
//        row++;
//    }

//    for (int i = 1; i < data.size(); i++) {
//        //comandManager->insertInfo(index, data.at(i));
//    }
//}

//void RemoveCommand::redo()
//{
//    //comandManager->deleteInfo(index);
//}



BaseCommand::BaseCommand(){}
