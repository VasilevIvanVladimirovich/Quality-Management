#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTableImportance()
{
    ui->tableWidgetImportance->clear();
    ui->tableWidgetImportance->setRowCount(0);
    ui->tableWidgetImportance->setColumnCount(0);
    Respon = ui->spinBoxRespondent->value();
    Criter = ui->spinBoxCriteria->value();
    ui->tableWidgetImportance->setRowCount(Respon);
    ui->tableWidgetImportance->setColumnCount(Criter);

    int *objectively = new int [Criter];
    for(int i = 0; i < Criter;i++)
    {
        objectively[i] = Random::get(1,10);
    }
    QStringList name_row;
    for(int i = 1; i <= Criter;i++)
    {
        name_row << "К " + QString::number(i);
    }
    QStringList name_col;
    for(int i = 1; i <= Respon;i++)
    {
        name_col << "Респондент " + QString::number(i);
    }
    QTableWidgetItem *newItem;
    int value;
    int randomValue;
    for(int y = 0;y < Criter; y++)
    {
        std::default_random_engine generator;
        std::normal_distribution<double> distribution(objectively[y], Random::get(1,4));
        for(int x = 0;x < Respon; x++)
        {
           randomValue = int(distribution(generator));
           if(randomValue<1)
               value = 1;
           else if(randomValue>10)
                value=10;
           else value = randomValue;
           newItem = new QTableWidgetItem(QString::number(value));
           ui->tableWidgetImportance->setItem(x,y,newItem);
       }
    }
    ui->tableWidgetImportance->setHorizontalHeaderLabels(name_row);
    ui->tableWidgetImportance->setVerticalHeaderLabels(name_col);
}

void MainWindow::createTableSatisfaction()
{

    ui->tableWidgetSatisfaction->clear();
    ui->tableWidgetSatisfaction->setRowCount(0);
    ui->tableWidgetSatisfaction->setColumnCount(0);
    Respon = ui->spinBoxRespondent->value();
    Criter = ui->spinBoxCriteria->value();
    ui->tableWidgetSatisfaction->setRowCount(Respon);
    ui->tableWidgetSatisfaction->setColumnCount(Criter);

    int *objectively = new int [Criter];
    for(int i = 0; i < Criter;i++)
    {
        objectively[i] = Random::get(1,10);
    }

    QStringList name_row;
    for(int i = 1; i <= Criter;i++)
    {
        name_row << "К " + QString::number(i);
    }
    QStringList name_col;
    for(int i = 1; i <= Respon;i++)
    {
        name_col << "Респондент " + QString::number(i);
    }
    QTableWidgetItem *newItem;
    int value;
    int randomValue;
    for(int y = 0;y < Criter; y++)
    {
        std::default_random_engine generator;
        std::normal_distribution<double> distribution(objectively[y], Random::get(1,4));
        for(int x = 0;x < Respon; x++)
        {
           randomValue = int(distribution(generator));
           if(randomValue<1)
               value = 1;
           else if(randomValue>10)
                value=10;
           else value = randomValue;
           newItem = new QTableWidgetItem(QString::number(value));
           ui->tableWidgetSatisfaction->setItem(x,y,newItem);
       }
    }

    ui->tableWidgetSatisfaction->setHorizontalHeaderLabels(name_row);
    ui->tableWidgetSatisfaction->setVerticalHeaderLabels(name_col);
}


void MainWindow::on_pushButton_clicked()
{
   createTableImportance();
   createTableSatisfaction();
}


void MainWindow::on_pushButton_2_clicked()
{
    Reports *windowReport = new Reports();
    windowReport->setTable(ui->tableWidgetImportance, ui->tableWidgetSatisfaction);
    windowReport->setResponCriter(Respon, Criter);
    windowReport->createRezult();
    windowReport->show();
}
