//Jakub Lemiesiewicz
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
void MainWindow::optymalize(){
    QString upLabel = ui->label->text();

}
void MainWindow::digital_pressed(){
    //qDebug() << "test";
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
bool MainWindow::isdothere(QString a){
    int l = a.length();
    for(int i = 0 ; i<l ; i++){
        if(a[i]=="."){
            return false;
        }
    }
    return true;
}
void MainWindow::on_pushButton_dot_released() {
    QString isdot = ui->label->text();
    if(isdothere(isdot)){
        ui->label->setText(ui->label->text()+".");
    }
}

void MainWindow::on_pushButton_plusminus_released() {
    //labelNumber = (ui->label->text() + button->text()).toDouble();
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
    checker = false;
}
void MainWindow::operation_pressed(){
    QPushButton * button = (QPushButton*)sender();
    if(button->text()=="+"){
        type = 1;
        qDebug() << "operation pressed";
        if(firstnumber==NULL){
            firstnumber = (ui->label->text()).toDouble();
            qDebug() << "first";
        } else {
            if(secondnumber==NULL){
                secondnumber = (ui->label->text()).toDouble();
            }
            /*
            result = firstnumber + secondnumber;
            firstnumber = result;
            qDebug() << "second";
            qDebug() << result;
            secondnumber = NULL;
            ui->label->setText(QString::number(result));*/
            ui->label->setText(QString::number(firstnumber+secondnumber));
            firstnumber=firstnumber+secondnumber;
            checker = false;
        }
    } else if (button->text()=="-"){
        type = 2;
        qDebug() << "type2";
    } else if (button->text()=="x"){
        type = 3;
        qDebug() << "mnoznie";
    } else if (button->text()=="/"){
        type = 4;
        qDebug() << "dzielenie";
    }
    lastoperation_equal = false;

}

void MainWindow::on_pushButton_equal_clicked()
{
    lastoperation_equal = true;
    if(result!=NULL){
        ui->label->setText(QString::number(result));
        qDebug() << "ello";
    } else {
        if(firstnumber!=NULL){
            if(type!=NULL){
                switch (type) {
                    case 1:{
                        if(secondnumber==NULL){
                            secondnumber = (ui->label->text()).toDouble();
                        }
                        ui->label->setText(QString::number(firstnumber+secondnumber));
                        firstnumber=firstnumber+secondnumber;
                        break;
                    }
                    case 2:{
                        qDebug() << "nothing";
                        break;
                    }
                    case 3:{
                        qDebug() << "3";
                        break;
                    }
                    case 4: {
                        qDebug() << "4";
                        break;
                    }
                    default: {
                        qDebug() <<"ERROR";
                    }
                }
            }
        }
    }
}
