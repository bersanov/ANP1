#include "calculator.h"
#include <math.h>
#include "ui_calculator.h"
long long a,b,m;
calculator::calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_pushButton1_clicked()
{
    a=a*10+1;
    ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_2_clicked()
{
     a=a*10+2;
    ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_3_clicked()
{   a=a*10+3;
    ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_4_clicked()
{
    a=a*10+4;
    ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_5_clicked()
{   a=a*10+5;
    ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_6_clicked()
{     a=a*10+6;
    ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_7_clicked()
{
    a=a*10+7;
        ui->lineEdit->setText(QString::number(a));

}
void calculator::on_pushButton_8_clicked()
{
    a=a*10+8;
        ui->lineEdit->setText(QString::number(a));

}
void calculator::on_pushButton_9_clicked()
{

    a=a*10+9;
        ui->lineEdit->setText(QString::number(a));
}
void calculator::on_pushButton_0_clicked()
{
    a=a*10+0;
        ui->lineEdit->setText(QString::number(a));
}
void calculator::on_plus_clicked()
{
    b=a;
    ui->lineEdit_3->setText(QString::number(a));
    ui->lineEdit->setText(0);
    a=0;
    m=1;

}
void calculator::on_pushButton_minus_clicked()
{
    b=a;
    ui->lineEdit_3->setText(QString::number(a));
    ui->lineEdit->setText(0);
    a=0;
    m=2;

}
void calculator::on_pushButton_umnozhit_clicked()
{
    b=a;
    ui->lineEdit_3->setText(QString::number(a));
    ui->lineEdit->setText(0);
    a=0;
    m=3;

}
void calculator::on_pushButton_clicked()
{
    a=pow(a,0.5);
    ui->lineEdit_2->setText(QString::number(a));
    a=0;
}
void calculator::on_pushButton_ravno_clicked()
{
    if(m==1)
    {
        a=a+b;
    }
    if(m==2)
    {
        a=b-a;
    }
    if(m==3)
    {
        a=a*b;
    }
    if(m==4)
    {
        a=pow(b,a);
    }
    if(m==5)
    {
        a=b/a;
    }


     ui->lineEdit_2->setText(QString::number(a));
}
void calculator::on_pushButtonstepen_clicked()
{
   b=a;
   a=0;
   m=4;
}
void calculator::on_pushButton_ravno_2_clicked()
{
    b=a;
    ui->lineEdit_3->setText(QString::number(a));
    ui->lineEdit->setText(0);
    a=0;
    m=5;
}
void calculator::on_pushButtonUDALIT_clicked()
{

        a=0;
        ui->lineEdit_3->setText(QString::number(a));
        b=0;
        ui->lineEdit->setText(QString::number(a));
         ui->lineEdit_2->setText(QString::number(a));


}
void calculator::on_pushButton_uDALSIMVOL_clicked()
{
    a=0;
    ui->lineEdit_3->setText(QString::number(a));
    b=0;
    ui->lineEdit->setText(QString::number(a));

}
void calculator::on_pushButtonKoren_clicked()
{

   a=sqrt(a);
   ui->lineEdit_2->setText(QString::number(a));
   a=0;
}
