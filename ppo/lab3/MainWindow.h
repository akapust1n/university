#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ComandManager.h"
#include "PluginInterface.h"
#include <QDir>
#include <QMainWindow>
#include <QPluginLoader>
#include <QSettings>
#include <QUndoStack>
#include <QVector>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:

    void on_setFont_clicked();

    void on_setBackground_clicked();

    void on_openFileButton_clicked();

public:
    QWidget* getWidgetsPlugins();
    Ui::MainWindow* ui;
    QUndoStack* undoStack;
    std::shared_ptr<ComandManager> comandManager;
    QSettings settings;

private:
    QDir pluginsDir;
    QVector<PluginAbstruct*> plugins;

private:
    void createSetting();

    void loadSettings();
    void loadPlugins();
};

#endif // MAINWINDOW_H
