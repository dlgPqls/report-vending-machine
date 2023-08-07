#include "widget.h"
#include "ui_widget.h" //Find current directory first
#include <QMessageBox> //first directory first

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);//init
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

//widget::
void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);//qt's qstring
    if((money-100) > 0){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }
    if((money-200)<0){
        ui->pbMilk->setEnabled(false);}
    if((money-150)<0){
        ui->pbTea->setEnabled(false);}
    if((money-100)<0){
        ui->pbCoffee->setEnabled(false);}
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    int fiveHundred = 0;
    int oneHundred = 0;
    int fifty = 0;
    int ten = 0;
    QString change;

    QMessageBox mb;
    if(money >= 500){
        fiveHundred = money / 500;
        money %= 500;
    }
    if(money >= 100){
        oneHundred = money / 100;
        money %= 100;
    }
    if(money >= 50){
        fifty = money / 50;
        money %= 50;
    }
    if(money >= 10){
        ten = money / 10;
        money %= 10;
    }
    if(fiveHundred > 0) change = "500: " + QString::number(fiveHundred) + "\n";
    if(oneHundred > 0) change += "100: " + QString::number(oneHundred)+"\n";
    if(fifty > 0) change += "50: "  + QString::number(fifty)+"\n";
    if(ten > 0) change += "10: " + QString::number(ten);
    mb.setText(change);
    mb.information(this, "Reset",change);
}


