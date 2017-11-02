#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <algorithm>
#include <bitset>
#include <functional>
#include <string>
using namespace std::placeholders;

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

double MainWindow::frequencyBitwiseTest(std::vector<int>& values)
{
    std::vector<int> results(values.size());
    int countNumbers = 0;
    //неудачное решение
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

double MainWindow::identicalConsecutiveBitstest(std::vector<int>& values)
{

    int countNumbers = 0;
    int sum = 0;
    auto toBinary = [](int value) {
        std::string temp = std::bitset<32>(value).to_string();
        if (temp.find('1', 0) != std::string::npos) {
            temp = temp.substr(temp.find("1"));

        } else {
            temp = "0";
        };
        return temp;
    };

    for (auto value : values) {
        std::string temp = toBinary(value);
        for (auto letter : temp) {
            if (letter == '1') {
                sum++;
            }
            countNumbers++;
        }
    };

    double stat = abs(sum) * 1.0 / countNumbers;
    if (abs(stat - 0.5) >= 2 / sqrt(countNumbers))
        return 0;

    int signChange = 0; // that's why
    std::string lastValue = "8";
    for (auto value : values) {
        std::string temp = toBinary(value);
        if (temp[0] != lastValue[0])
            signChange++;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] != temp[i - 1]) {
                signChange++;
            }
        }
        lastValue = temp[temp.size() - 1];
    };

    double p = erfc(abs(signChange - 2 * countNumbers * stat * (1 - stat)) / (2 * stat * (1 - stat) * sqrt(2 * countNumbers)));

    return p;
}

void MainWindow::on_pushButton_2_clicked()
{
    int numTab = ui->tabWidget->currentIndex();
    int numLines = ui->numLines->text().toInt();

    auto test = [=](int index, QTableWidget* table, std::function<double(std::vector<int>&)> testFunct, int offset) {
        std::vector<int> values;
        for (int i = 0; i < numLines; i++) {
            values.push_back(table->item(i, index)->text().toInt());
        }
        double testValue = testFunct(values);
        QTableWidgetItem* newItem = new QTableWidgetItem(QString::number(testValue));
        table->setRowCount(numLines + offset);
        table->setItem(numLines + offset - 1, index, newItem);
    };
    std::function<double(std::vector<int>&)> funct0 = std::bind(&MainWindow::frequencyBitwiseTest, this, _1); //не знаю как нормально сделать
    std::function<double(std::vector<int>&)> funct1 = std::bind(&MainWindow::identicalConsecutiveBitstest, this, _1); //identicalConsecutiveBitstest

    switch (numTab) {
    case algoritm: {

        test(0, ui->Algtable, funct0, 1);
        test(1, ui->Algtable, funct0, 1);
        test(2, ui->Algtable, funct0, 1);

        test(0, ui->Algtable, funct1, 2);
        test(1, ui->Algtable, funct1, 2);
        test(2, ui->Algtable, funct1, 2);
        break;
    }
    case table: {
        test(0, ui->tableTable, funct0, 1);
        test(1, ui->tableTable, funct0, 1);
        test(2, ui->tableTable, funct0, 1);

        test(0, ui->tableTable, funct1, 2);
        test(1, ui->tableTable, funct1, 2);
        test(2, ui->tableTable, funct1, 2);
        break;
    }
    case custom: {
        test(0, ui->customTable, funct0, 1);
        test(1, ui->customTable, funct0, 1);
        test(2, ui->customTable, funct0, 1);

        test(0, ui->customTable, funct1, 2);
        test(1, ui->customTable, funct1, 2);
        test(2, ui->customTable, funct1, 2);
        break;
    }

    default:
        break;
    }
}
