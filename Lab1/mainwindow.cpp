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
    ui->tableWidgetImportance->setRowCount(Respon+6);
    ui->tableWidgetImportance->setColumnCount(Criter);
    QStringList name_row;
    for(int i = 1; i <= Criter;i++)
    {
        name_row << "Критерий " + QString::number(i);
    }
    QStringList name_col;
    for(int i = 1; i <= Respon;i++)
    {
        name_col << "Респондент " + QString::number(i);
    }
    QTableWidgetItem *newItem;
    int value;
    for(int x = 0;x < Respon; x++)
    {
       for(int y = 0;y < Criter; y++)
       {
           value = Random::get(0,10);
           newItem = new QTableWidgetItem(QString::number(value));
           ui->tableWidgetImportance->setItem(x,y,newItem);
       }
    }

    name_col << "Среднее x"; //row
    int sum;
    double xr;
    for(int y = 0; y < Criter; y++)
    {
        sum=0;
        for(int x = 0;x < Respon; x++)
        {
           sum += ui->tableWidgetImportance->item(x,y)->text().toInt();
        }
        xr = double(sum) / double(Respon);
        newItem = new QTableWidgetItem(QString::number(xr, 'f', 2));
        ui->tableWidgetImportance->setItem(Respon,y,newItem);
    }

    name_col << "Максимальная x"; //row
    int max;
    for(int y = 0; y < Criter; y++)
    {
        max = 0;
        for(int x = 0;x < Respon; x++)
        {
           max = qMax(max, ui->tableWidgetImportance->item(x,y)->text().toInt());
        }
        newItem = new QTableWidgetItem(QString::number(max));
        ui->tableWidgetImportance->setItem(Respon+1,y,newItem);
    }

    name_col << "Минимальное x"; //row
    int min;
    for(int y = 0; y < Criter; y++)
    {
        min = 10;
        for(int x = 0;x < Respon; x++)
        {
           min = qMin(min, ui->tableWidgetImportance->item(x,y)->text().toInt());
        }
        newItem = new QTableWidgetItem(QString::number(min));
        ui->tableWidgetImportance->setItem(Respon+2,y,newItem);
    }
    name_col << "Отклоение"; //row
    double otcl;
    for(int y = 0; y < Criter; y++)
    {
        sum=0;
        for(int x = 0;x < Respon; x++)
        {
           sum += qPow(double(ui->tableWidgetImportance->item(x,y)->text().toInt()) - ui->tableWidgetImportance->item(Respon,y)->text().toDouble(),2);
        }
        otcl =  qSqrt((1 / double(Respon))*sum);
        newItem = new QTableWidgetItem(QString::number(otcl, 'f', 2));
        ui->tableWidgetImportance->setItem(Respon+3,y,newItem);
    }

    name_col << "Весовой коэфициент"; //row
    double B;
    sum=0;
    for(int i = 0; i < Criter;i++)
    {
        sum+=ui->tableWidgetImportance->item(Respon,i)->text().toDouble();
    }
    for(int y = 0; y < Criter; y++)
    {
        for(int x = 0;x < Respon; x++)
        {
           B = ui->tableWidgetImportance->item(Respon,y)->text().toDouble() / sum;
        }
        newItem = new QTableWidgetItem(QString::number(B, 'f', 2));
        ui->tableWidgetImportance->setItem(Respon+4,y,newItem);
    }

    name_col << "Взвешенная оценка"; //row
    double O;
    for(int y = 0; y < Criter; y++)
    {
        for(int x = 0;x < Respon; x++)
        {
           O = ui->tableWidgetImportance->item(Respon+4,y)->text().toDouble() * ui->tableWidgetImportance->item(Respon,y)->text().toDouble() ;
        }
        newItem = new QTableWidgetItem(QString::number(O, 'f', 2));
        ui->tableWidgetImportance->setItem(Respon+5,y,newItem);
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
    ui->tableWidgetSatisfaction->setRowCount(Respon+6);
    ui->tableWidgetSatisfaction->setColumnCount(Criter);
    QStringList name_row;
    for(int i = 1; i <= Criter;i++)
    {
        name_row << "Критерий " + QString::number(i);
    }
    QStringList name_col;
    for(int i = 1; i <= Respon;i++)
    {
        name_col << "Респондент " + QString::number(i);
    }
    QTableWidgetItem *newItem;
    int value;
    for(int x = 0;x < Respon; x++)
    {
       for(int y = 0;y < Criter; y++)
       {
           value = Random::get(0,10);
           newItem = new QTableWidgetItem(QString::number(value));
           ui->tableWidgetSatisfaction->setItem(x,y,newItem);
       }
    }

    name_col << "Среднее x"; //row
    int sum;
    double xr;
    for(int y = 0; y < Criter; y++)
    {
        sum=0;
        for(int x = 0;x < Respon; x++)
        {
           sum += ui->tableWidgetSatisfaction->item(x,y)->text().toInt();
        }
        xr = double(sum) / double(Respon);
        newItem = new QTableWidgetItem(QString::number(xr, 'f', 2));
        ui->tableWidgetSatisfaction->setItem(Respon,y,newItem);
    }

    name_col << "Максимальная x"; //row
    int max;
    for(int y = 0; y < Criter; y++)
    {
        max = 0;
        for(int x = 0;x < Respon; x++)
        {
           max = qMax(max, ui->tableWidgetSatisfaction->item(x,y)->text().toInt());
        }
        newItem = new QTableWidgetItem(QString::number(max));
        ui->tableWidgetSatisfaction->setItem(Respon+1,y,newItem);
    }

    name_col << "Минимальное x"; //row
    int min;
    for(int y = 0; y < Criter; y++)
    {
        min = 10;
        for(int x = 0;x < Respon; x++)
        {
           min = qMin(min, ui->tableWidgetSatisfaction->item(x,y)->text().toInt());
        }
        newItem = new QTableWidgetItem(QString::number(min));
        ui->tableWidgetSatisfaction->setItem(Respon+2,y,newItem);
    }
    name_col << "Отклоение"; //row
    double otcl;
    for(int y = 0; y < Criter; y++)
    {
        sum=0;
        for(int x = 0;x < Respon; x++)
        {
           sum += qPow(double(ui->tableWidgetSatisfaction->item(x,y)->text().toInt()) - ui->tableWidgetSatisfaction->item(Respon,y)->text().toDouble(),2);
        }
        otcl =  qSqrt((1 / double(Respon))*sum);
        newItem = new QTableWidgetItem(QString::number(otcl, 'f', 2));
        ui->tableWidgetSatisfaction->setItem(Respon+3,y,newItem);
    }

    name_col << "Весовой коэфициент"; //row
    double B;
    sum=0;
    for(int i = 0; i < Criter;i++)
    {
        sum+=ui->tableWidgetSatisfaction->item(Respon,i)->text().toDouble();
    }
    for(int y = 0; y < Criter; y++)
    {
        for(int x = 0;x < Respon; x++)
        {
           B = ui->tableWidgetSatisfaction->item(Respon,y)->text().toDouble() / sum;
        }
        newItem = new QTableWidgetItem(QString::number(B, 'f', 2));
        ui->tableWidgetSatisfaction->setItem(Respon+4,y,newItem);
    }

    name_col << "Взвешенная оценка"; //row
    double O;
    for(int y = 0; y < Criter; y++)
    {
        for(int x = 0;x < Respon; x++)
        {
           O = ui->tableWidgetSatisfaction->item(Respon+4,y)->text().toDouble() * ui->tableWidgetSatisfaction->item(Respon,y)->text().toDouble() ;
        }
        newItem = new QTableWidgetItem(QString::number(O, 'f', 2));
        ui->tableWidgetSatisfaction->setItem(Respon+5,y,newItem);
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
    windowReport->replot();
    windowReport->show();
}
