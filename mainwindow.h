#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qmainwindow.h>
#include <qstringlist.h>
class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionOpen_CALC_triggered();

    void on_actionpCAP_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
