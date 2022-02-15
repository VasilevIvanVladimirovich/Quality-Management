#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

namespace Ui {
class Reports;
}

class Reports : public QWidget
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();

    void setTable(QTableWidget* tableImportance,QTableWidget* tableSatisfaction);
    void replot();
    void setResponCriter(int Respon, int Criter);

private:
    Ui::Reports *ui;

    QTableWidget *tableImportance_;
    QTableWidget *tableSatisfaction_;

    int Respon_;
    int Criter_;
};

#endif // REPORTS_H
