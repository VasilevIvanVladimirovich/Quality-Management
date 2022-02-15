#include "reports.h"
#include "ui_reports.h"

Reports::Reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
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
    QBarSet *set0 = new QBarSet("Важность");
    QBarSet *set1 = new QBarSet("Удовлетворённость");

    for(int y = 0 ; y < Criter_; y++)
    {
        *set0 << tableImportance_->item(Respon_,y)->text().toDouble();
        *set1 << tableSatisfaction_->item(Respon_,y)->text().toDouble();
    }
    QStringList categories;
    for(int i = 0 ; i < Criter_ ;i++)
    {
        categories << tableImportance_->horizontalHeaderItem(i)->text();
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
}

void Reports::setResponCriter(int Respon, int Criter)
{
    Respon_ = Respon;
    Criter_ = Criter;
}
