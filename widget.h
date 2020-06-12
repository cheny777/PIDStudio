#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegendMarker>
#include <QValueAxis>
#include <QDebug>
#include <QPainter>
#include <QQueue>
#include <pid.h>
#include <transfunc.h>

//QT_CHARTS_USE_NAMESPACE

#define PI 3.1415926535

using namespace QtCharts;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    /*创建表*/
    QChart *m_charts;
    /*创建数据源*/
    QLineSeries *series;

    /*初始化曲线*/
    void initChart();

    /*
    *还有新建一个series作为图表的数据源：
    *QBarSeries （用于创建柱状图）
    *QHorizontalBarSeries （用于创建水平柱状图）
    *QHorizontalPercentBarSeries （用于创建水平百分比柱状图）
    *QHorizontalStackedBarSeries （用于创建水平层叠图）
    *QPercentBarSeries （用于创建百分比柱状图）QStackedBarSeries （用于创建层叠图/堆叠的条形图）
    *QAreaSeries （用于创建面积图）
    *QBoxPlotSeries （用于创建箱形图/盒须图）
    *QPieSeries （用于创建饼图）
    *QXYSeries （线性图、曲线图、散点图的基类）
    *QLineSeries （用于创建折线图）
    *QSplineSeries （用于创建曲线图）
    *QScatterSeries （用于创建散点图）
    **/

    /*曲线容器*/
    QList<QLineSeries *> m_series;
    /*点列容器*/
    QQueue<double> doubleList;
    /*更新数据*/
    void updataChart();
    /*周期*/
    double m_period;
    /*频率*/
    double m_frequency;
    /*振幅*/
    double m_amplitude;


    /*测试一*/
    PID *m_pid;
    double m_p1;
    double m_i1;
    double m_d1;
    TransFunc *m_tf;



protected:
    void timerEvent(QTimerEvent *);
private slots:
    void slotSliderPeriod(int num);
    void slotSliderAmplitude(int num);

    void slotSpinBoxPeriod(int num);
    void slotSpinBoxAmplitude(int num);

    void onSilderKpChanged(int value);
    void onSilderKiChanged(int value);
    void onSilderKdChanged(int value);

    void slotSetPID_p(double num);
    void slotSetPID_i(double num);
    void slotSetPID_d(double num);

};

#endif // WIDGET_H
