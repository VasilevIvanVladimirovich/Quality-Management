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

void MainWindow::generateDate()
{
    /* координаты падения шарика формируются в Полярных координатах(distributionCorner,distributionLeng)
     * Затем координата Длинна корректируется для моделирования кучности
     * попадания шарика на мишень (newLength_)
    */

    std::random_device generator;
    //генерация равномерного распределения угла от 0 до 360 градусов
    std::normal_distribution<double> distributionCorner(0.0,360.0);
    //генерация равномерного распределения длинны от 0 до 100 единиц
    std::normal_distribution<double> distributionLeng(0.0,30.0);
    //генерация равномерного распределения служебной переменной (для формирования новой длинны)
    std::normal_distribution<double> distributionOfficial(0.0,1.0);
    for(int i = 0;i<countCast_;i++)
    {
        corners_.push_back(distributionCorner(generator));

        length_.push_back(distributionLeng(generator));

        official_.push_back(distributionOfficial(generator));

        if(length_[i] > 0)
            newLength_.push_back(length_[i] * distributionOfficial(generator));
        else newLength_.push_back(length_[i]);

        //заполнение декартовых координат, x - косинус угла на длинну, y - синус угла на длинну
        double x = distributionLeng(generator);
        double y = distributionLeng(generator);
        coordinates_.push_back(QPair<double,double>(x, y));

        //coordinates_.push_back(QPair<double,double>(qCos(qDegreesToRadians(corners_[i]))*newLength_[i],qSin(qDegreesToRadians(corners_[i]))*newLength_[i]));
    }
}

void MainWindow::createRuleOne()
{
    QScatterSeries *series = new QScatterSeries();
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);

    for(int i = 0;i < countCast_;i++)
    {
        *series << QPointF(coordinates_[i].first,coordinates_[i].second);
        lengthOne_.push_back(sqrt((coordinates_[i].first * coordinates_[i].first)+(coordinates_[i].second * coordinates_[i].second)));
    }

    QChart *chartRuleOne = new QChart();

    QLineSeries* lineX = new QLineSeries();
    lineX->setColor(Qt::black);
    *lineX << QPointF(-200, 0) << QPointF(200, 0);
    QLineSeries* lineY = new QLineSeries();
    lineY->setColor(Qt::black);
    *lineY << QPointF(0, -200) << QPointF(0, 200);
    chartRuleOne->addSeries(lineX);
    chartRuleOne->addSeries(lineY);

    chartRuleOne->addSeries(series);
    chartRuleOne->setTitle("Правило 1");
    chartRuleOne->createDefaultAxes();
    chartRuleOne->axisY()->setRange(-200,200);
    chartRuleOne->axisX()->setRange(-200,200);

    QChartView *chartViewRuleOne = new QChartView(chartRuleOne);
    chartViewRuleOne->setParent(ui->frameRuleOne);
    chartViewRuleOne->show();


    ui->LineMaxOne->setText(QString::number(*std::max_element(lengthOne_.constBegin(), lengthOne_.constEnd())));
    ui->lineMinOne->setText(QString::number(*std::min_element(lengthOne_.constBegin(), lengthOne_.constEnd())));
    ui->lineAvgOne->setText(QString::number(std::accumulate(lengthOne_.begin(), lengthOne_.end(), .0) / lengthOne_.size()));
    rangAvg_.push_back(std::accumulate(lengthOne_.begin(), lengthOne_.end(), .0) / lengthOne_.size());
}

void MainWindow::createRuleTwo()
{
    QScatterSeries *series = new QScatterSeries();
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);
    double x,y;

    if(countCast_ > 0)
    {
        *series << QPointF(coordinates_[0].first,coordinates_[0].second);
        lengthTwo_.push_back(sqrt((coordinates_[0].first * coordinates_[0].first)+(coordinates_[0].second * coordinates_[0].second)));
    }

    for(int i = 1; i < countCast_;i++)
    {
        x = coordinates_[i].first - coordinates_[i-1].first;
        y = coordinates_[i].second - coordinates_[i-1].second;
        *series << QPointF(x, y);
        lengthTwo_.push_back(sqrt((x * x)+(y * y)));
    }

    QChart *chartRuleTwo = new QChart();

    QLineSeries* lineX = new QLineSeries();
    lineX->setColor(Qt::black);
    *lineX << QPointF(-200, 0) << QPointF(200, 0);
    QLineSeries* lineY = new QLineSeries();
    lineY->setColor(Qt::black);
    *lineY << QPointF(0, -200) << QPointF(0, 200);
    chartRuleTwo->addSeries(lineX);
    chartRuleTwo->addSeries(lineY);

    chartRuleTwo->addSeries(series);
    chartRuleTwo->setTitle("Правило 2");
    chartRuleTwo->createDefaultAxes();
    chartRuleTwo->axisY()->setRange(-200,200);
    chartRuleTwo->axisX()->setRange(-200,200);

    QChartView *chartViewRuleTwo = new QChartView(chartRuleTwo);
    chartViewRuleTwo->setParent(ui->frameRuleTwo);
    chartViewRuleTwo->show();

    ui->lineMaxSecond->setText(QString::number(*std::max_element(lengthTwo_.constBegin(), lengthTwo_.constEnd())));
    ui->lineMinSecond->setText(QString::number(*std::min_element(lengthTwo_.constBegin(), lengthTwo_.constEnd())));
    ui->lineSecondAvg->setText(QString::number(std::accumulate(lengthTwo_.begin(), lengthTwo_.end(), .0) / lengthTwo_.size()));
    rangAvg_.push_back(std::accumulate(lengthTwo_.begin(), lengthTwo_.end(), .0) / lengthTwo_.size());
}

void MainWindow::createRuleThird()
{
    QScatterSeries *series = new QScatterSeries();
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);
    double x,y;

    if(countCast_ > 0)
    {
        x = coordinates_[0].first;
        y = coordinates_[0].second;
        *series << QPointF(x,y);
        lengthThird_.push_back(sqrt((coordinates_[0].first * coordinates_[0].first)+(coordinates_[0].second * coordinates_[0].second)));
    }

    for(int i = 1; i < countCast_;i++)
    {
        x = coordinates_[i].first - x;
        y = coordinates_[i].second - y;
        *series << QPointF(x, y);
        lengthThird_.push_back(sqrt((x * x)+(y * y)));
    }

    QChart *chartRuleThird = new QChart();

    QLineSeries* lineX = new QLineSeries();
    lineX->setColor(Qt::black);
    *lineX << QPointF(-200, 0) << QPointF(200, 0);
    QLineSeries* lineY = new QLineSeries();
    lineY->setColor(Qt::black);
    *lineY << QPointF(0, -200) << QPointF(0, 200);
    chartRuleThird->addSeries(lineX);
    chartRuleThird->addSeries(lineY);

    chartRuleThird->addSeries(series);
    chartRuleThird->setTitle("Правило 3");
    chartRuleThird->createDefaultAxes();
    chartRuleThird->axisY()->setRange(-200,200);
    chartRuleThird->axisX()->setRange(-200,200);

    QChartView *chartViewRuleThird = new QChartView(chartRuleThird);
    chartViewRuleThird->setParent(ui->frameRuleThird);
    chartViewRuleThird->show();

    ui->lineMaxThird->setText(QString::number(*std::max_element(lengthThird_.constBegin(), lengthThird_.constEnd())));
    ui->lineMinThird->setText(QString::number(*std::min_element(lengthThird_.constBegin(), lengthThird_.constEnd())));
    ui->lineAvgThird->setText(QString::number(std::accumulate(lengthThird_.begin(), lengthThird_.end(), .0) / lengthThird_.size()));
    rangAvg_.push_back(std::accumulate(lengthThird_.begin(), lengthThird_.end(), .0) / lengthThird_.size());
}

void MainWindow::createRuleFourth()
{
    QScatterSeries *series = new QScatterSeries();
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);
    double x,y;

    if(countCast_ > 0)
    {
        x = coordinates_[0].first;
        y = coordinates_[0].second;
        *series << QPointF(x,y);
        lengthFourth_.push_back(sqrt((coordinates_[0].first * coordinates_[0].first)+(coordinates_[0].second * coordinates_[0].second)));
    }

    for(int i = 1; i < countCast_;i++)
    {
        x = coordinates_[i].first + x;
        y = coordinates_[i].second + y;
        *series << QPointF(x, y);
        lengthFourth_.push_back(sqrt((x * x)+(y * y)));
    }

    QChart *chartRuleFourth = new QChart();

    QLineSeries* lineX = new QLineSeries();
    *lineX << QPointF(-200, 0) << QPointF(200, 0);
    lineX->setColor(Qt::black);
    QLineSeries* lineY = new QLineSeries();
    lineY->setColor(Qt::black);
    *lineY << QPointF(0, -200) << QPointF(0, 200);
    chartRuleFourth->addSeries(lineX);
    chartRuleFourth->addSeries(lineY);

    chartRuleFourth->addSeries(series);
    chartRuleFourth->setTitle("Правило 4");
    chartRuleFourth->createDefaultAxes();
    chartRuleFourth->axisY()->setRange(-200,200);
    chartRuleFourth->axisX()->setRange(-200,200);

    QChartView *chartViewRuleFourth = new QChartView(chartRuleFourth);
    chartViewRuleFourth->setParent(ui->frameRuleFourth);
    chartViewRuleFourth->show();

    ui->linMaxFourth->setText(QString::number(*std::max_element(lengthFourth_.constBegin(), lengthFourth_.constEnd())));
    ui->lineMinFourth->setText(QString::number(*std::min_element(lengthFourth_.constBegin(), lengthFourth_.constEnd())));
    ui->lineAvgFourth->setText(QString::number(std::accumulate(lengthFourth_.begin(), lengthFourth_.end(), .0) / lengthFourth_.size()));
    rangAvg_.push_back(std::accumulate(lengthFourth_.begin(), lengthFourth_.end(), .0) / lengthFourth_.size());
}

void MainWindow::getRang()
{
    QVector<double> sortRangAvg;
    QVector<int> rangs;
    for(int i = 0; i < 4;i++)
    {
        sortRangAvg.push_back(rangAvg_[i]);
    }
    std::sort(sortRangAvg.begin(),sortRangAvg.end());
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j< sortRangAvg.count();j++)
            if(rangAvg_[i]==sortRangAvg[j]) rangs.push_back(j);
    }
    ui->lineRangOne->setText(QString::number(rangs[0]+1));
    ui->lineRangSecond->setText(QString::number(rangs[1]+1));
    ui->lineRangThird->setText(QString::number(rangs[2]+1));
    ui->lineRangFourth->setText(QString::number(rangs[3]+1));
}

void MainWindow::clearDate()
{
    countCast_ = 1;

    corners_.clear();
    length_.clear();
    newLength_.clear();
    official_.clear();
    coordinates_.clear();

    lengthOne_.clear();
    lengthTwo_.clear();
    lengthThird_.clear();
    lengthFourth_.clear();

    rangAvg_.clear();
}


void MainWindow::on_pushButton_clicked()
{
    countCast_ = ui->spinBoxCast->value();
    generateDate();
    createRuleOne();
    createRuleTwo();
    createRuleThird();
    createRuleFourth();
    getRang();
    clearDate();
}

