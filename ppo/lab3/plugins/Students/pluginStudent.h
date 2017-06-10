#include <QObject>
#include <QtPlugin>
#include <QStringList>
#include <QImage>

#include "../../PluginInterface.h"
#include "../../MainWindow.h"
#include "/home/alexey/16/university/ppo/build/ui_MainWindow.h" //Сначала должна быть скомпилена основная программа

class StudentsPlugin : public QObject, public PluginAbstruct
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.StudentPlugin" FILE "pluginStudents.json")
  Q_INTERFACES(PluginAbstruct)

public:
  QVariant doThing(MainWindow *_th) override;
  public slots:
  void onOpenFileClicked();
};
