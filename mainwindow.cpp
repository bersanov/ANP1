#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include "pcap.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_CALC_triggered()
{
    calculator *zzz  = new calculator (this);
    zzz->show();

}


void MainWindow::on_actionpCAP_triggered()
{
    PCAP *rrr = new PCAP (this);
    rrr->show();
}
