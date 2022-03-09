#include "reports.h"
#include "ui_reports.h"

Reports::Reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
    resize(1280,850);
}

Reports::~Reports()
{
    delete ui;
}

void Reports::setTable(QTableWidget* tableImportance,QTableWidget* tableSatisfaction)
{
    tableImportance_ = tableImportance;
    tableSatisfaction_ = tableSatisfaction;
}

void Reports::replot()
{
    //Гистограмм
    QBarSet *set0 = new QBarSet("Важность");
    QBarSet *set1 = new QBarSet("Удовлетворённость");

    for(int y = 0 ; y < Criter_; y++)
    {
        *set0 << ui->tableWidget->item(1,y)->text().toDouble();
        *set1 << ui->tableWidget->item(0,y)->text().toDouble();
    }
    QStringList categories;
    for(int i = 0 ; i < Criter_ ;i++)
    {
        categories << ui->tableWidget->horizontalHeaderItem(i)->text();
    }
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Bar Chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->axisY()->setRange(0,10);
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->frame1);

    //Точки
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Важность/Удовлетворённость");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(15.0);

    QLineSeries* series1 = new QLineSeries();
    *series1 << QPointF(5, 0) << QPointF(5, 10);
    QLineSeries* series2 = new QLineSeries();
    *series2 << QPointF(0, 5) << QPointF(10, 5);

    for(int i = 0;i < Criter_;i++)
    {
        *series0 <<QPointF(ui->tableWidget->item(1,i)->text().toDouble(),
                           ui->tableWidget->item(0,i)->text().toDouble());
    }
    //важность x
    QChart *chart2 = new QChart();
    chart2->addSeries(series0);
    chart2->addSeries(series1);
    chart2->addSeries(series2);
    chart2->setTitle("Соотношение важность/удовлетворенность");
    chart2->createDefaultAxes();
    chart2->axisY()->setRange(0,10);
    chart2->axisY()->setTitleText("Удовлетворенность");
    chart2->axisX()->setRange(0,10);
    chart2->axisX()->setTitleText("Важность");
    chart2->setDropShadowEnabled(false);

    QChartView *chartView2 = new QChartView(chart2);
    chartView2->setParent(ui->frame2);
}

void Reports::setResponCriter(int Respon, int Criter)
{
    Respon_ = Respon;
    Criter_ = Criter;
}

void Reports::createRezult()
{

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(7);
    ui->tableWidget->setColumnCount(Criter_);

    QStringList name_col;
    for(int i = 0 ; i < Criter_ ;i++)
    {
        name_col << tableImportance_->horizontalHeaderItem(i)->text();
    }
    QStringList name_row;

    name_row<<"Среднее удовлетворённость"
            <<"Средняя важность"
            <<"Максимальная оценка"
            <<"Минимальная оценка"
            <<"Среднеквадратичное отклонение"
            <<"Весовой коэффицент"
            <<"Взвешенная оценка";

    QTableWidgetItem *newItem;
    int sum;
    double xr;
    for(int y = 0; y < Criter_; y++)
    {
        sum=0;
        for(int x = 0;x < Respon_; x++)
        {
            sum += tableSatisfaction_->item(x,y)->text().toInt();
        }
        xr = double(sum) / double(Respon_);
        newItem = new QTableWidgetItem(QString::number(xr, 'f', 2));
        ui->tableWidget->setItem(0,y,newItem);
     }

    for(int y = 0; y < Criter_; y++)
    {
        sum=0;
        for(int x = 0;x < Respon_; x++)
        {
            sum += tableImportance_->item(x,y)->text().toInt();
        }
        xr = double(sum) / double(Respon_);
        newItem = new QTableWidgetItem(QString::number(xr, 'f', 2));
        ui->tableWidget->setItem(1,y,newItem);
     }

    int max;
    for(int y = 0; y < Criter_; y++)
    {
        max = 0;
        for(int x = 0;x < Respon_; x++)
        {
            max = qMax(max, tableSatisfaction_->item(x,y)->text().toInt());
        }
        newItem = new QTableWidgetItem(QString::number(max));
        ui->tableWidget->setItem(2,y,newItem);
    }

    int min;
    for(int y = 0; y < Criter_; y++)
    {
        min = 10;
        for(int x = 0;x < Respon_; x++)
        {
            min = qMin(min, tableSatisfaction_->item(x,y)->text().toInt());
        }
           newItem = new QTableWidgetItem(QString::number(min));
           ui->tableWidget->setItem(3,y,newItem);
    }

    //отклоление
    double otcl;
    double summ;
    for(int y = 0; y < Criter_; y++)
    {
        summ=0;
        for(int x = 0;x < Respon_; x++)
        {
            summ += qPow(double(tableSatisfaction_->item(x,y)->text().toInt()) - ui->tableWidget->item(0,y)->text().toDouble(),2);
        }
        otcl =  qSqrt((1 / double(Respon_-1))*summ);
        newItem = new QTableWidgetItem(QString::number(otcl, 'f', 2));
        ui->tableWidget->setItem(4,y,newItem);
    }

    //весовой коэфф
    double B;
    int *sumImportance = new int [Criter_] {0};
    sum=0;
    for(int i = 0; i < Criter_;i++)
    {
        for(int r=0;r<Respon_;r++)
        {
            sumImportance[i]+=tableImportance_->item(r,i)->text().toInt();
        }
        sum+=sumImportance[i];
    }
    for(int i = 0;i < Criter_; i++)
    {
        B = double(sumImportance[i]) / double(sum);
        newItem = new QTableWidgetItem(QString::number(B, 'f', 2));
        ui->tableWidget->setItem(5,i,newItem);
    }

    //Взвешенная оценка
    double O;
    summ = 0;
    for(int y = 0; y < Criter_; y++)
    {
        for(int x = 0;x < Respon_; x++)
        {
            O = ui->tableWidget->item(0,y)->text().toDouble() * ui->tableWidget->item(5,y)->text().toDouble() ;
        }
        summ += O;
        newItem = new QTableWidgetItem(QString::number(O, 'f', 2));
        ui->tableWidget->setItem(6,y,newItem);
    }

    ui->label->setText("Удовлетворённость потребителя: " + QString::number(qCeil(summ/10*100))+"%");
    ui->tableWidget->setHorizontalHeaderLabels(name_col);
    ui->tableWidget->setVerticalHeaderLabels(name_row);
    replot();
}
