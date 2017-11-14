#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class calculator;
}

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();

private:
    Ui::calculator *ui;
public slots :

private slots:
    void on_pushButton1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_umnozhit_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_clicked();
    void on_pushButton_ravno_clicked();
    void on_pushButton_udalenie_clicked();
    void on_pushButton_stepen_clicked();
    void on_pushButton_deltnie_clicked();
    void on_pushButtonstepen_clicked();
    void on_pushButton_ravno_2_clicked();
    void on_pushButtonUDALIT_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_uDALSIMVOL_clicked();
    void on_pushButtonKoren_clicked();
};

#endif // CALCULATOR_H
