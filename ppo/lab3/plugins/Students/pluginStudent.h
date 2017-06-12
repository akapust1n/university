#include <QImage>
#include <QObject>
#include <QStringList>
#include <QtPlugin>

#include "../../MainWindow.h"
#include "../../PluginInterface.h"
#include "../../ui_MainWindow.h" //Сначала должна быть скомпилена основная программа
#include <QUndoStack>
#include <QWidget>
#include <QTreeView>

class StudentsPlugin : public QObject, public PluginAbstruct {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.StudentPlugin" FILE "pluginStudents.json")
    Q_INTERFACES(PluginAbstruct)

public:
    QVariant doThing(MainWindow* _th) override;
public slots:
    void onOpenFileClicked();
    void  onRemoveStudentsClicked();
    void onInsertClicked();
    void onChangeClicked();



private:
    QWidget* PluginsWidget;
    QUndoStack* undoStack;
    QTreeView *treeView;
    QModelIndexList list;
    TreeModel *treeModel;
    Tree *tree;
};
