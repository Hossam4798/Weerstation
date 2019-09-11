#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineSeries *series = new QLineSeries();

    series->append(0,6);
    series->append(2,4);
    series->append(3,8);
    series->append(7,4);
    series->append(10,5);

    *series << QPointF(0,0) << QPointF(13,3) << QPointF(17,6) << QPointF(18,3) << QPointF(20,2);

    QChart *chart = new QChart();
    chart ->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Weerstation gegevens temperatuur");

    QChartView *chartView = new QChartView(chart);
    chartView -> setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();

    return a.exec();
}
