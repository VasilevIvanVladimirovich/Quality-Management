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
// Рекомендации
// если расхождения в пределах погрешности...

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
    chart->setTitle("Диаграмма расхождений");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->axisY()->setRange(0,10);
    chart->setAxisX(axis,series);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->frame1);

    //Таблица разницы
    ui->tableDiscrepancy->clear();
    ui->tableDiscrepancy->setRowCount(Criter_);
    ui->tableDiscrepancy->setColumnCount(1);
    ui->tableDiscrepancy->setColumnWidth(0,500);
    ui->tableDiscrepancy->setVerticalHeaderLabels(categories);

    QTableWidgetItem *newItem = new QTableWidgetItem();
    QString line="";
    for(int i =0;i < Criter_;i++)
    {
        if((set0->at(i)>set1->at(i)-0.5 & set0->at(i)<set1->at(i)+0.5)|
           (set1->at(i)>set0->at(i)-0.5 & set1->at(i)<set0->at(i)+0.5))
            line= "критерий является стабильным местом в работе предприятия";
        else if(set0->at(i) > set1->at(i))
            line= "критерий является слабым местом в работе предприятия";
        else if(set0->at(i) < set1->at(i))
            line= "критерий является сильной стороной работы предприятия";
        newItem = new QTableWidgetItem(line);
        ui->tableDiscrepancy->setItem(i,0,newItem);
    }

    //гистограмма важности
    QBarSeries *seriestImpot  = new QBarSeries();
    seriestImpot->append(set0);

    QChart *chartImpot = new QChart();
    chartImpot->addSeries(seriestImpot);
    chartImpot->setTitle("Диаграмма важности");
    chartImpot->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisImpot = new QBarCategoryAxis();
    axisImpot->append(categories);
    chartImpot->createDefaultAxes();
    chartImpot->axisY()->setRange(0,10);
    chartImpot->setAxisX(axisImpot,seriestImpot);
    QChartView *chartViewImpot = new QChartView(chartImpot);
    chartViewImpot->setParent(ui->frameImpotant);

    //Таблица важности
    ui->tableImpotant->clear();
    ui->tableImpotant->setRowCount(Criter_);
    ui->tableImpotant->setColumnCount(1);
    ui->tableImpotant->setVerticalHeaderLabels(categories);
    ui->tableImpotant->setColumnWidth(0,500);

    line="";
    for(int i =0;i < Criter_;i++)
    {
        if(set0->at(i) > 8)
            line = "Высокая заинтересованность потребителей";
        else if(set0->at(i) < 5)
            line = "Низкая заинтересованность потребителей";
        else line = "Заинтересованность";

        newItem = new QTableWidgetItem(line);
        ui->tableImpotant->setItem(i,0,newItem);
    }

    //гистограмма удовлетворённости
    QBarSeries *seriestSatis  = new QBarSeries();
    seriestSatis->append(set1);

    QChart *chartSatis = new QChart();
    chartSatis->addSeries(seriestSatis);
    chartSatis->setTitle("Диаграмма удовлетворённости");
    chartSatis->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisSatis = new QBarCategoryAxis();
    axisSatis->append(categories);
    chartSatis->createDefaultAxes();
    chartSatis->axisY()->setRange(0,10);
    chartSatis->setAxisX(axisSatis,seriestSatis);
    QChartView *chartViewSatis = new QChartView(chartSatis);
    chartViewSatis->setParent(ui->frameSatisfaction);

    //Таблица удовлетворённости
    ui->tableSatisfaction->clear();
    ui->tableSatisfaction->setRowCount(Criter_);
    ui->tableSatisfaction->setColumnCount(1);
    ui->tableSatisfaction->setVerticalHeaderLabels(categories);
    ui->tableSatisfaction->setColumnWidth(0,500);

    line="";
    for(int i =0;i < Criter_;i++)
    {
        if(set1->at(i) > 8)
            line = "Высокая удовлетворенность потребителей";
        else if(set1->at(i) < 5)
            line = "Низкая удовлетворенность потребителей";
        else line = "Удовлетворенность";

        newItem = new QTableWidgetItem(line);
        ui->tableSatisfaction->setItem(i,0,newItem);
    }

    //Точки

    QVector<QScatterSeries*> vactorScatter;
    for(int i=0; i < Criter_; i++)
    {
        QScatterSeries *seriesScatter = new QScatterSeries();
        seriesScatter->setName(categories[i]);
        seriesScatter->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        seriesScatter->setMarkerSize(15.0);
        *seriesScatter<<QPointF(ui->tableWidget->item(1,i)->text().toDouble(),
                        ui->tableWidget->item(0,i)->text().toDouble());
        vactorScatter.push_back(seriesScatter);
    }

    double sredImportance,sredSatisfaction;
    double sum=0;
    for(int i = 0;i<Criter_;i++)
    {
        sum+=ui->tableWidget->item(1,i)->text().toDouble();
    }
    sredImportance=sum/Criter_;
    QLineSeries* series1 = new QLineSeries();
    *series1 << QPointF(sredImportance, 0) << QPointF(sredImportance, 10);
    series1->setColor(QColor(0,0,0));

    sum=0;
    for(int i = 0;i<Criter_;i++)
    {
        sum+=ui->tableWidget->item(0,i)->text().toDouble();
    }
    sredSatisfaction=sum/Criter_;
    QLineSeries* series2 = new QLineSeries();
    *series2 << QPointF(0, sredSatisfaction) << QPointF(10, sredSatisfaction);
    series2->setColor(QColor(0,0,0));

    //важность x
    QChart *chart2 = new QChart();
    for(int i = 0; i < Criter_;i++)
    {
        chart2->addSeries(vactorScatter[i]);
    }
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

    //таблица точек
    ui->tablePoint->clear();
    ui->tablePoint->setRowCount(Criter_);
    ui->tablePoint->setColumnCount(1);
    ui->tablePoint->setColumnWidth(0,500);
    ui->tablePoint->setVerticalHeaderLabels(categories);

    for(int i =0;i < Criter_;i++)
    {

        if(set0->at(i)>=sredImportance & set1->at(i)>=sredSatisfaction)
            line="Критерий важен и потребитель удовлетворен";
        else if(set0->at(i) <= sredImportance & set1->at(i) >= sredSatisfaction)
            line="Критерий не важен, но потребитель удовлетворен";
        else if(set0->at(i) >= sredImportance & set1->at(i) <= sredSatisfaction)
            line="Критерий важен, но потребитель не удовлетворен";
        else if(set0->at(i) <= sredImportance & set1->at(i) <= sredSatisfaction)
            line="Критерий не важен и потребитель не удовлетворен";

        newItem = new QTableWidgetItem(line);
        ui->tablePoint->setItem(i,0,newItem);
    }
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
    QString line="";
    double satisfaction;
    satisfaction = summ/10*100;
    if(satisfaction >= 90)
        line = "потребители удовлетворены";
    else if(satisfaction < 90 & satisfaction > 70)
        line = "потребители удовлетворены, но имеются небольшие замечания";
    else if(satisfaction <=70 & satisfaction >= 50)
        line = "удовлетворенность потребителей низкая";
    else
        line = "потребители неудовлетворены";
    ui->label->setText("Удовлетворённость потребителя: " + QString::number(qCeil(summ/10*100))+"%" + " " + line);
    ui->tableWidget->setHorizontalHeaderLabels(name_col);
    ui->tableWidget->setVerticalHeaderLabels(name_row);














    replot();
}
