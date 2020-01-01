#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double firstnumber = NULL, secondnumber = NULL, result = NULL;
    bool checker = false;
    int type = NULL;
    bool lastoperation_equal = false;
private:
    Ui::MainWindow *ui;

private slots:
    void optymalize();
    void digital_pressed();

    void on_pushButton_dot_released();


    bool isdothere(QString a);
    void on_pushButton_plusminus_released();
    void on_pushButton_C_clicked();
    void operation_pressed();
    void on_pushButton_equal_clicked();
};
#endif // MAINWINDOW_H
