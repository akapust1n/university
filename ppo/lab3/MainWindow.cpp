#include "MainWindow.h"
#include "QTextEdit"
#include "ui_MainWindow.h"
#include <Comands.h>
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    undoStack = new QUndoStack(this);
    comandManager.reset(new ComandManager);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QVBoxLayout* layout = new QVBoxLayout();
    ui->pluginsWidget->setLayout(layout);
    loadSettings();
    loadPlugins();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setFont_clicked()
{

    bool ok = false;
    int fontSize = QInputDialog::getInt(this, tr("Input"), tr("Font size"), ui->treeView->font().pointSize(), 1, 50, 1, &ok);
    if (ok) {
        QFont fnt = ui->treeView->font();
        fnt.setPointSize(fontSize);
        ui->treeView->setFont(fnt);
        createSetting();
    }
}

void MainWindow::on_setBackground_clicked()
{
    QColor bg = QColorDialog::getColor();
    QPalette palet = ui->treeView->palette();
    palet.setColor(QPalette::Text, bg);
    ui->treeView->setPalette(palet);
    createSetting();
}
void MainWindow::createSetting()
{
    settings.beginGroup("Check");
    settings.setValue("isExist", true);
    settings.endGroup();

    settings.beginGroup("TreeView");
    QColor color = ui->treeView->palette().text().color();
    settings.setValue("fontColor", color);
    int fontSize = ui->treeView->font().pointSize();
    settings.setValue("fontSize", fontSize);
    settings.endGroup();
}
void MainWindow::loadSettings()
{
    settings.beginGroup("Check");
    if (settings.value("isExist").isValid()) {
        settings.endGroup();

        settings.beginGroup("TreeView");
        QColor color = settings.value("fontColor").value<QColor>();
        QPalette palet;
        palet.setColor(QPalette::Text, color);
        ui->treeView->setPalette(palet);

        int fontSize = settings.value("fontSize").toInt();
        QFont fnt = ui->treeView->font();
        fnt.setPointSize(fontSize);
        ui->treeView->setFont(fnt);
        settings.endGroup();
    } else {
        settings.endGroup();
        createSetting();
    }
}

void MainWindow::on_openFileButton_clicked()
{
    // QPushButton * btn =new QPushButton("ss");
    //ui->centralWidget->layout()->addWidget(btn);
    //QTextEdit *te = new QTextEdit();

    // ui->pluginWidget->layout()->addWidget(te);
}

QWidget* MainWindow::getWidgetsPlugins()
{
    return ui->pluginsWidget;
}

void MainWindow::loadPlugins()
{
    pluginsDir = QDir(qApp->applicationDirPath());

    pluginsDir.cd("/home/alexey/16/university/ppo/lab3/plugins");

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        if (loader.load()) {
            qDebug() << fileName << " loaded";
            QObject* plugin = loader.instance();
            if (plugin) {
                plugins.push_back(qobject_cast<PluginAbstruct*>(plugin));
                plugins.last()->doThing(this);
                // populateContext(plugin);
                // pluginFileNames += fileName;
            }
        } else {
            qDebug() << loader.isLoaded() << loader.errorString();
        }
    }
}
