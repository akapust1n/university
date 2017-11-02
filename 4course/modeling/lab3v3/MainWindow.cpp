#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <algorithm>
#include <bitset>
#include <string>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gen(std::random_device()())
    , dis09(0, 9)
    , dis1099(10, 99)
    , dis100999(100, 999)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int numTab = ui->tabWidget->currentIndex();
    int numLines = ui->numLines->text().toInt();
    switch (numTab) {
    case algoritm: {
        ui->Algtable->clear();
        ui->Algtable->setRowCount(numLines);
        ui->Algtable->setColumnCount(3);

        break;
    }
    case table: {
        ui->tableTable->clear();
        ui->tableTable->setRowCount(numLines);
        ui->tableTable->setColumnCount(3);
        break;
    }
    case custom: {
        ui->customTable->clear();
        ui->customTable->setRowCount(numLines);
        ui->customTable->setColumnCount(3);
        break;
    }

    default:
        break;
    }
    createHeaders((typeTable)numTab);
    fillTable((typeTable)numTab, numLines);
}

void MainWindow::createHeaders(MainWindow::typeTable type)
{
    switch (type) {
    case algoritm: {

        ui->Algtable->setHorizontalHeaderItem(0, new QTableWidgetItem("0-9"));

        ui->Algtable->setHorizontalHeaderItem(1, new QTableWidgetItem("10-99"));
        ui->Algtable->setHorizontalHeaderItem(2, new QTableWidgetItem("100-999"));

        break;
    }
    case table: {
        ui->tableTable->setHorizontalHeaderItem(0, new QTableWidgetItem("0-9"));

        ui->tableTable->setHorizontalHeaderItem(1, new QTableWidgetItem("10-99"));
        ui->tableTable->setHorizontalHeaderItem(2, new QTableWidgetItem("100-999"));

        break;
    }
    case custom: {
        ui->customTable->setHorizontalHeaderItem(0, new QTableWidgetItem("0-9"));

        ui->customTable->setHorizontalHeaderItem(1, new QTableWidgetItem("10-99"));
        ui->customTable->setHorizontalHeaderItem(2, new QTableWidgetItem("100-999"));
        break;
    }

    default:
        break;
    }
}

void MainWindow::fillTable(MainWindow::typeTable type, int numLines)
{

    switch (type) {
    case algoritm: {
        for (int i = 0; i < numLines; i++) {
            QTableWidgetItem* newItem1 = new QTableWidgetItem(QString::number(dis09(gen)));
            ui->Algtable->setItem(i, 0, newItem1);
            QTableWidgetItem* newItem2 = new QTableWidgetItem(QString::number(dis1099(gen)));
            ui->Algtable->setItem(i, 1, newItem2);
            QTableWidgetItem* newItem3 = new QTableWidgetItem(QString::number(dis100999(gen)));
            ui->Algtable->setItem(i, 2, newItem3);
        }

        break;
    }
    case table: {
        for (int i = 0; i < numLines; i++) {

            QTableWidgetItem* newItem1 = new QTableWidgetItem(QString::number(getTableValue(10)));
            ui->tableTable->setItem(i, 0, newItem1);
            QTableWidgetItem* newItem2 = new QTableWidgetItem(QString::number(getTableValue(100)));
            ui->tableTable->setItem(i, 1, newItem2);
            QTableWidgetItem* newItem3 = new QTableWidgetItem(QString::number(getTableValue(1000)));
            ui->tableTable->setItem(i, 2, newItem3);
        }

        break;
    }
    case custom: {
        ui->customTable->setHorizontalHeaderItem(0, new QTableWidgetItem("0-9"));

        ui->customTable->setHorizontalHeaderItem(1, new QTableWidgetItem("10-99"));
        ui->customTable->setHorizontalHeaderItem(2, new QTableWidgetItem("100-999"));
        break;
    }

    default:
        break;
    }
}

int MainWindow::getTableValue(int div)
{
    static int counter = -1;
    if (counter >= array.size())
        counter = -1;
    counter++;
    return array[counter] % div;
}

double MainWindow::testValues(std::vector<int>& values)
{
    std::vector<int> results(values.size());
    int countNumbers = 0;
    std::transform(values.begin(), values.end(), results.begin(), [&countNumbers](int value) {
        std::string temp = std::bitset<32>(value).to_string();
        if (temp.find('1', 0) != std::string::npos) {
            temp = temp.substr(temp.find("1"));

        } else {
            temp = "0";
        };
        int counter = 0;
        for (auto letter : temp) {
            if (letter == '1') {
                counter++;
            } else {
                counter--;
            }
            countNumbers++;
        }
        return counter;
    });
    int sum = 0;
    for (auto number : results) {
        sum += number;
    }
    double stat = abs(sum) * 1.0 / sqrt(countNumbers);
    double _erfc = std::erfc(stat / sqrt(2));
    return _erfc;
}

void MainWindow::on_pushButton_2_clicked()
{
    int numTab = ui->tabWidget->currentIndex();
    int numLines = ui->numLines->text().toInt();

    auto test = [=](int index, QTableWidget* table) {
        std::vector<int> values;
        for (int i = 0; i < numLines; i++) {
            values.push_back(table->item(i, index)->text().toInt());
        }
        double testValue = testValues(values);
        QTableWidgetItem* newItem = new QTableWidgetItem(QString::number(testValue));
        table->setRowCount(numLines + 1);
        table->setItem(numLines, index, newItem);
    };
    switch (numTab) {
    case algoritm: {

        test(0, ui->Algtable);
        test(1, ui->Algtable);
        test(2, ui->Algtable);
        break;
    }
    case table: {
        test(0, ui->tableTable);
        test(1, ui->tableTable);
        test(2, ui->tableTable);
        break;
    }
    case custom: {
        test(0, ui->customTable);
        test(1, ui->customTable);
        test(2, ui->customTable);
        break;
    }

    default:
        break;
    }
}
