#include <QFontDatabase>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int idFont = QFontDatabase::addApplicationFont("../Store/fonts/friends.ttf");
    QString friends = QFontDatabase::applicationFontFamilies(idFont).at(0);
    QFont IC(friends);
    IC.setPixelSize(16);
    this->setFont(IC);


    QPixmap bg("../Store/Images/background.jpg");
    ui->background->setPixmap(bg);
    ui->background2->setPixmap(bg);
    ui->background3->setPixmap(bg);
    ui->background4->setPixmap(bg);

    QPixmap pix("../Store/Images/CentralPerkLogo.png");
    ui->logo->setPixmap(pix);
    ui->logo2->setPixmap(pix);
    ui->logo3->setPixmap(pix);
    ui->logo4->setPixmap(pix);
}

struct Item
{
    string itemName;
    float itemPrice = 0;
};

vector<Item> v;
double total = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

//////////////////////////////////////////////
// NAVIGATION BUTTONS
//////////////////////////////////////////////

void MainWindow::on_buttonViewCart_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    string str;

    for (int i = 0; i < v.size(); i++)
    {
        str = v[i].itemName + "\t\t" + to_string(v[i].itemPrice);
        ui->itemsInCart->addItem(str.c_str());
        total += v[i].itemPrice;
    }

    str = to_string(total);
    ui->TotalPriceInCart->setText(str.c_str());
}


void MainWindow::on_buttonBackToSelection_clicked()
{
    ui->itemsInCart->clear();
    v.clear();
    total = 0;
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_buttonPay_clicked()
{
    string str = to_string(total);
    ui->TotalPriceInCart_2->setText(str.c_str());

    ui->stackedWidget->setCurrentIndex(2);
}


struct receipt
{
    int receiptNum;
    QString customerName, cardNum;

};

void MainWindow::on_buttonConfirm_clicked()
{

    ofstream outputFile;
    receipt rec;
    rec.receiptNum = rand() % (100000000 - 1000000 + 1) + 10000000;
    rec.customerName = ui->textEditName->toPlainText();
    rec.cardNum = ui->textEditCardNumber->toPlainText();

    outputFile.open("Receipt.txt", ios::app);

    if (outputFile)
    {
        outputFile << "\n  Receipt Number: " << rec.receiptNum << "\n";
        outputFile << "-----------------------------------\n";
        outputFile << "  Customer Name: " << rec.customerName.toStdString() << "\n";
        outputFile << "  Card Number: " << rec.cardNum.toStdString() << "\n";
        outputFile << "-----------------------------------\n";
        outputFile << "  Items \t\t Price\n";
        for (int i = 0; i < v.size(); i++)
        {

            outputFile << "  " << v[i].itemName << "\t\t" << (v[i].itemPrice) << "\n";
        }

        outputFile << "-----------------------------------\n";
        outputFile << "  Total: \t\t" << total << "\n";
        outputFile << "-----------------------------------\n";
    }

    ui->stackedWidget->setCurrentIndex(3);

    outputFile.close();
}

void MainWindow::on_buttonConfirm_2_clicked()
{
    ui->itemsInCart->clear();
    v.clear();
    total = 0;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonBackToCart_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


//////////////////////////////////////////////
// adding drinks
//////////////////////////////////////////////

void MainWindow::on_buttonAddEspresso_clicked()
{
    Item espresso;
    espresso.itemName = "Espresso";
    espresso.itemPrice = 3.90;

    v.push_back(espresso);
}


void MainWindow::on_buttonAddCapucchino_clicked()
{
    Item capucchino;
    capucchino.itemName = "Capucchino";
    capucchino.itemPrice = 5.90;
    v.push_back(capucchino);
}


void MainWindow::on_buttonAddLatte_clicked()
{
    Item latte;
    latte.itemName = "Latte";
    latte.itemPrice = 5.90f;

    v.push_back(latte);
}


void MainWindow::on_buttonAddFrappucchino_clicked()
{
    Item frappucchino;
    frappucchino.itemName = "Frappucchino";
    frappucchino.itemPrice = 7.90f;

    v.push_back(frappucchino);
}


void MainWindow::on_buttonAddIcedTeas_clicked()
{
    Item icedTeas;
    icedTeas.itemName = "Iced Tea";
    icedTeas.itemPrice = 4.9;

    v.push_back(icedTeas);
}




