#include "calculator.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* calculator calculator;
    calculator.setWindowTitle("Calculator");
    calculator.resize(250,200);
    calculator.setFixedSize(500,300);
    calculator.show();
       */
    MainWindow w;
    w.show();


    return a.exec();
}
