//Jakub Lemiesiewicz

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
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

MainWindow::~MainWindow() {
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
    thirdchecker = true;
    secondchecker = true;
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if(lastoperation_equal){
            lastoperation_equal = false;
            goto A;
        } else if(firstnumber==NULL){
            B:
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

void MainWindow::equal(){
    if(type!=NULL){
    }
}

void MainWindow::anotherfunc(){
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
            A:
            result = firstnumber+secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    } else if (lastoperation_equal) {
            goto A;
        }else if(thirdchecker){
            thirdchecker = false;
        } else {
            if(lasttype == 1){
                result = firstnumber+secondnumber;
                firstnumber=result;
                qDebug() << secondnumber << result;
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
            A:
            result = firstnumber-secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    } else if (lastoperation_equal) {
        goto A;
    }else if(thirdchecker){
        thirdchecker = false;
    } else {
        if(lasttype == 2){
            result = firstnumber-secondnumber;
            firstnumber=result;
            qDebug() << secondnumber << result;
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
            A:
            result = firstnumber*secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    } else if (lastoperation_equal) {
        goto A;
    }else if(thirdchecker){
        thirdchecker = false;
    } else {
        if(lasttype == 3){
            result = firstnumber*secondnumber;
            firstnumber=result;
            qDebug() << secondnumber << result;
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
            A:
            result = firstnumber/secondnumber;
            ui->label->setText(QString::number(result));
            firstnumber=result;
            checker = false;
        }
    } else if (lastoperation_equal) {
        goto A;
    }else if(thirdchecker){
        thirdchecker = false;
    } else {
        if(lasttype == 4){
            result = firstnumber/secondnumber;
            firstnumber=result;
            qDebug() << secondnumber << result;
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
    lasttype = NULL;
}

void MainWindow::type_(){
    if(lasttype!=NULL){
        switch (lasttype) {
            case 1:{
                dodawanie();
                break;
            }
            case 2:{
                odejmowanie();
                break;
            }
            case 3:{
                mnozenie();
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
    if(!thirdchecker){
        qDebug() << "tuu" << type << lasttype;
        type = lasttype;
        QPushButton * button = (QPushButton*)sender();
        if(button->text()=="+"){
            lasttype = 1;
        } else if (button->text()=="-"){
            lasttype = 2;

            qDebug() << "type2";
        } else if (button->text()=="x"){
                lasttype = 3;
        } else if (button->text()=="/"){
                lasttype = 4;
            }
        if(type!=lasttype){
            thirdchecker = true;
        }
        type_();
        ui->label->setText(QString::number(result));
        lastoperation_equal = false;
    } else {
        if(type!=NULL){
            lasttype = type;
        }
        type_();
        checker = false;
        QPushButton * button = (QPushButton*)sender();
        if(button->text()=="+"){
            lasttype = 1;
            type_();
        } else if (button->text()=="-"){
            lasttype = 2;
            qDebug() << "type2";
            type_();
        } else if (button->text()=="x"){
                qDebug() << lasttype;
                if(lasttype == 1 || lasttype==2){
                    if(thirdnumber!=NULL){
                        kolejnosc = true;
                    } else {
                        anotherfunc();
                    }
                }
                lasttype = 3;
                type_();
        } else if (button->text()=="/"){
                qDebug() << lasttype;
                if(lasttype == 1 || lasttype == 2){
                    if(thirdnumber!=NULL){
                        kolejnosc = true;
                    } else {
                        anotherfunc();
                    }
                }
                lasttype = 4;
                type_();
            }
    }
    lastoperation_equal = false;
}

void MainWindow::on_pushButton_equal_clicked() {
    lastoperation_equal = true;
    qDebug() << type << lasttype;
    type_();
    ui->label->setText(QString::number(result));
}

void MainWindow::on_pushButton_proccent_released() {
    double labelNumber = (ui->label->text()).toDouble()/100;
    QString newLabel = QString::number(labelNumber);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_del_clicked() {
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

void MainWindow::on_pushButton_sqrt_clicked() {
    double labelNumber = (ui->label->text()).toDouble();
    double sqrtNumber = sqrt(labelNumber);
    QString sqrtLabel = QString::number(sqrtNumber);
    ui->label->setText(sqrtLabel);
}

void MainWindow::on_pushButton_pow_clicked() {
    double labelNumber = (ui->label->text()).toDouble();
    double powNumber = pow(labelNumber,2);
    QString powLabel = QString::number(powNumber);
    ui->label->setText(powLabel);
}

void MainWindow::on_pushButton_1x_clicked() {
    double labelNumber = (ui->label->text()).toDouble();
    double revNumber = 1/labelNumber;
    QString revLabel = QString::number(revNumber);
    ui->label->setText(revLabel);
}
