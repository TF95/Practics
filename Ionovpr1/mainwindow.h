#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector <int> vec = QVector <int> (10000);
    QString str;
    QString arr;
    QString vr;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void Sort();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
