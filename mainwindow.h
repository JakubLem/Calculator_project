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
    double firstnumber = NULL, secondnumber = NULL,thirdnumber = NULL, result = NULL;
    bool checker = false;
    int type = NULL;
    bool lastoperation_so = false;
    bool lastoperation_equal = false;
    bool secondchecker = true;
    int lasttype = NULL;
    bool thirdchecker = true;
    bool kolejnosc = false;


private:
    Ui::MainWindow *ui;

private slots:
    void optymalize();
    void digital_pressed();
    void equal();
    void dodawanie();
    void odejmowanie();
    void mnozenie();
    void dzielenie();
    void on_pushButton_dot_released();
    void type_();
    void anotherfunc(); //funkcja odpowiedzialna za działania w przypadku innej kolejności wykonywania działań ++ X
    bool isdothere(QString a);
    void on_pushButton_plusminus_released();
    void on_pushButton_C_clicked();
    void operation_pressed();
    void on_pushButton_equal_clicked();
    void on_pushButton_proccent_released();
    void on_pushButton_del_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_1x_clicked();
};
#endif // MAINWINDOW_H
