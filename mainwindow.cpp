//Jakub Lemiesiewicz
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digital_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digital_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_x,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_dzielenie,SIGNAL(released()),this,SLOT(operation_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::isdothere(QString a){
    int l = a.length();
    for(int i = 0 ; i<l ; i++){
        if(a[i]=="."){
            return false;
        }
    }
    return true;
}
void MainWindow::optymalize(){
    QString upLabel = ui->label->text();

}
void MainWindow::digital_pressed(){
    //qDebug() << "test";
    secondchecker = true;
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if(lastoperation_equal){
        lastoperation_equal = false;
        goto A;
    } else if(firstnumber==NULL){
        labelNumber = (ui->label->text() + button->text()).toDouble();
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    } else {
        if (checker == false){
            A:
            labelNumber = (button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
            ui->label->setText(newLabel);
            checker = true;
        } else {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
            ui->label->setText(newLabel);
        }
    }
}

void MainWindow::on_pushButton_dot_released() {
    QString isdot = ui->label->text();
    if(isdothere(isdot)){
        ui->label->setText(ui->label->text()+".");
    }
}
void MainWindow::another(){
    qDebug() << "another";
}
void MainWindow::dodawanie(){

    qDebug() << "operation pressed";
    if(secondchecker){
        if(firstnumber==NULL){
            firstnumber = (ui->label->text()).toDouble();
            qDebug() << "first";
        } else {
            if(secondchecker){
                secondnumber = (ui->label->text()).toDouble();
                secondchecker = false;
            }
            result = firstnumber+secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    }
}
void MainWindow::odejmowanie(){
    if(secondchecker){
        if(firstnumber==NULL){
            firstnumber = (ui->label->text()).toDouble();
            qDebug() << "first";
        } else {
            if(secondchecker){
                secondnumber = (ui->label->text()).toDouble();
                secondchecker = false;
            }
            result = firstnumber-secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    }

}
void MainWindow::mnozenie(){
    if(secondchecker){
        if(firstnumber==NULL){
            firstnumber = (ui->label->text()).toDouble();
            qDebug() << "mnozenie";
        } else {
            if(secondchecker){
                secondnumber = (ui->label->text()).toDouble();
                secondchecker = false;
            }
            result = firstnumber*secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    }

}
void MainWindow::dzielenie(){
    if(secondchecker){
        if(firstnumber==NULL){
            firstnumber = (ui->label->text()).toDouble();
            qDebug() << "first";
        } else {
            if(secondchecker){
                secondnumber = (ui->label->text()).toDouble();
                secondchecker = false;
            }
            result = firstnumber/secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    }
}
void MainWindow::on_pushButton_plusminus_released() {
    double labelNumber = (ui->label->text()).toDouble();
    QString newLabel;
    labelNumber = -1* labelNumber;
    newLabel = QString::number(labelNumber);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_C_clicked() {
    ui->label->setText("0");
    firstnumber = NULL;
    secondnumber = NULL;
    type = NULL;
    checker = false;
    secondchecker = true;
    lastoperation_equal = false;
}
void MainWindow::type_(){
    if(type!=NULL){
        switch (type) {
            case 1:{
                dodawanie();
                break;
            }
            case 2:{
                odejmowanie();
                break;
            }
            case 3:{
                if(type==1 || type==2){
                    another();
                } else {
                    mnozenie();
                }
                break;
            }
            case 4: {
                dzielenie();
                break;
            }
            default: {
                qDebug() <<"ERROR";
            }
        }
    }
}
void MainWindow::operation_pressed(){
    QPushButton * button = (QPushButton*)sender();
    if(button->text()=="+"){
        type = 1;
        type_();
    } else if (button->text()=="-"){
        type = 2;
        type_();
        qDebug() << "type2";
    } else if (button->text()=="x"){
        if(type==1 || type==2){
            another();
        } else {
            type = 3;
            type_();
        }
    } else if (button->text()=="/"){
        type = 4;
        type_();
        qDebug() << "dzielenie";
    }
    lastoperation_equal = false;
}

void MainWindow::on_pushButton_equal_clicked()
{
    //lastoperation_equal = true;
    type_();
    ui->label->setText(QString::number(result));
}

void MainWindow::on_pushButton_proccent_released()
{
    double labelNumber = (ui->label->text()).toDouble()/100;
    QString newLabel = QString::number(labelNumber);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_del_clicked()
{
    double labelNumber = (ui->label->text()).toDouble();
    if(labelNumber!=0){
        QString newLabel = QString::number(labelNumber);
        int x = newLabel.length();
        if(x==1){
            ui->label->setText("0");
        } else {
            newLabel.remove(x-1,x);
            ui->label->setText(newLabel);
        }
    }
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    double labelNumber = (ui->label->text()).toDouble();
    double sqrtNumber = sqrt(labelNumber);
    QString sqrtLabel = QString::number(sqrtNumber);
    ui->label->setText(sqrtLabel);
}

void MainWindow::on_pushButton_pow_clicked()
{
    double labelNumber = (ui->label->text()).toDouble();
    double powNumber = pow(labelNumber,2);
    QString powLabel = QString::number(powNumber);
    ui->label->setText(powLabel);
}

void MainWindow::on_pushButton_1x_clicked()
{
    double labelNumber = (ui->label->text()).toDouble();
    double revNumber = 1/labelNumber;
    QString revLabel = QString::number(revNumber);
    ui->label->setText(revLabel);
}
