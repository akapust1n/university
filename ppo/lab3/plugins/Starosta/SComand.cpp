#include "SComand.h"
#include <QMessageBox>

void SCommand::redo()
{
    QMessageBox box;
    box.setText("¯\\_(ツ)_/¯");
    box.exec();
}

void SCommand::undo()
{
}

SCommand::SCommand(QModelIndex _index)
    : index(_index)
{
}
