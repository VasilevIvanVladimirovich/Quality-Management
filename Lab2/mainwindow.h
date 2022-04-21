#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
#include <QtCharts>
#include <QChartView>
#include <QScatterSeries>
#include <algorithm>

#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generateDate();
    void createRuleOne();
    void createRuleTwo();
    void createRuleThird();
    void createRuleFourth();
    void getRang();
    void clearDate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


    int countCast_;

    QVector<double> corners_;
    QVector<double> length_;
    QVector<double> newLength_;
    QVector<double> official_;
    QVector<QPair<double,double>> coordinates_;

    QVector<double> lengthOne_;
    QVector<double> lengthTwo_;
    QVector<double> lengthThird_;
    QVector<double> lengthFourth_;

    QVector<double> rangAvg_;
};
#endif // MAINWINDOW_H
