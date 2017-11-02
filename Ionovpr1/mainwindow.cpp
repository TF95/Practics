#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    for (int i=0;i<vec.size();i++)
    {
        vec[i] = rand () % 100;
    }

    for (int i=0;i<vec.size();i++)
    {
        str+=QString::number(vec[i]);

        if(i<vec.size()-1)
            str += " ";
    }

    arr = str;

    connect (ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(Sort()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}

void MainWindow::Sort()
{
    ui->textEdit->clear();
    str.clear();

    if (ui->comboBox->currentText()=="Sort")
    {
        unsigned int start_time =  clock();
        sort(vec.begin(), vec.end());
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        for (int i=0;i<vec.size();i++)
        {
            str+=QString::number(vec[i]);
            if(i<vec.size()-1)
                str += " ";
        }

        vr+=QString::number(search_time);

        ui->textEdit->setText(str);

        ui->textEdit_2->setText(vr+" млс");

        search_time=0;
        vr.clear();
    }

    if (ui->comboBox->currentText()=="Bubble")
    {

        unsigned int start_time =  clock();
        for (int i = 0; i <vec.size(); i++) {
            for (int j = 0; j < vec.size()-1; j++) {
                if (vec[j] > vec[j + 1])
                {
                    swap(vec[j],vec[j+1]);
                }
            }
        }
        unsigned int end_time = clock();

        unsigned int search_time = (end_time - start_time)/1000;

        for (int i=0;i<vec.size();i++)
        {
            str+=QString::number(vec[i]);
            if(i<vec.size()-1)
                str += " ";
        }

        ui->textEdit->setText(str);

        vr+=QString::number(search_time);

        ui->textEdit_2->setText(vr+" сек");

        search_time=0;

        vr.clear();
    }

    vec.clear();
}

void MainWindow::on_pushButton_2_clicked()
{
        ui->textEdit->setText(arr);
        ui->textEdit_2->clear();
}
