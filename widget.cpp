#include "widget.h"
#include "ui_widget.h"
#include <math.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1000,500);
    startTimer(50);
    initChart();

    m_amplitude = 3;
    m_period = 20;

    ui->spinBox->setValue(20);
    ui->spinBox_2->setValue(3);



    ui->periodSlider->setMinimum(1);
    ui->periodSlider->setMaximum(101);
    ui->periodSlider->setValue(20);

    ui->amplitudeSlider->setMinimum(1);
    ui->amplitudeSlider->setMaximum(101);
    ui->amplitudeSlider->setValue(300/5.0);

    ui->silderKp->setMinimum(0);
    ui->silderKp->setMaximum(1000);
    ui->silderKi->setMinimum(0);
    ui->silderKi->setMaximum(1000);
    ui->silderKd->setMinimum(0);
    ui->silderKd->setMaximum(2000);

    connect(ui->silderKp, SIGNAL(valueChanged(int)), this, SLOT(onSilderKpChanged(int)));
    connect(ui->silderKi, SIGNAL(valueChanged(int)), this, SLOT(onSilderKiChanged(int)));
    connect(ui->silderKd, SIGNAL(valueChanged(int)), this, SLOT(onSilderKdChanged(int)));

    connect(ui->spinBoxKp, SIGNAL(valueChanged(double)), this, SLOT(slotSetPID_p(double)));
    connect(ui->spinBoxKi, SIGNAL(valueChanged(double)), this, SLOT(slotSetPID_i(double)));
    connect(ui->spinBoxKd, SIGNAL(valueChanged(double)), this, SLOT(slotSetPID_d(double)));


    connect(ui->periodSlider,SIGNAL(valueChanged(int)),this,SLOT(slotSliderPeriod(int)));
    connect(ui->amplitudeSlider,SIGNAL(valueChanged(int)),this,SLOT(slotSliderAmplitude(int)));

    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(slotSpinBoxPeriod(int)));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(slotSpinBoxAmplitude(int)));

    m_p1 = 0;
    m_i1 = 0;
    m_d1 = 0;

    m_pid = new PID(m_p1,m_i1,m_d1);
    m_tf = new TransFunc;


}

Widget::~Widget()
{
    delete ui;
}

void Widget::initChart()
{
    m_charts = new QChart;

    ui->widget->setChart(m_charts);
    //防止图形走样
    ui->widget->setRenderHint(QPainter::Antialiasing);

    series = new QLineSeries;
    m_series.push_back(series);
    //创建数据源
    series->setPen(QPen(Qt::red,1,Qt::SolidLine));//设置曲线显示效


    QLineSeries *series_mubiao = new QLineSeries;
    series_mubiao->setPen(QPen(Qt::blue,2,Qt::SolidLine));
    series_mubiao->append(0,5);
    series_mubiao->append(1000,5);

     m_charts->addSeries(series_mubiao);//输入数据


    m_charts->setTitle("正弦图");
    //m_charts->setAnimationOptions(QChart::SeriesAnimations);//设置曲线动画模式
    //m_charts->legend()->hide(); //隐藏图例
    m_charts->addSeries(series);//输入数据
    //m_charts->setAxisX(axisX, series);
    //m_charts->setAxisY(axisY, series);

    m_charts->createDefaultAxes(); //建立默认坐标轴，不需要QValueAxis
    m_charts->axisY()->setRange(-20, 20);//默认坐标轴限定范围
    m_charts->axisX()->setRange(0, 200);//默认坐标轴限定范围
}

void Widget::updataChart()
{
    //series[0].clear();
    series->clear();
    for(int i = 0;i<doubleList.size();i++)
    {
        series->append(i,doubleList[i]);
    }

}

void Widget::timerEvent(QTimerEvent *)
{
    static int X = 0;

    double Y =m_amplitude*sin(X*(2*PI)/m_period)+5;
    X++;
    if(X == m_period*10)
    {
        X=0;
    }

    m_pid->setValue(Y);
    Y = m_pid->iteration(5);


    static int i = 0;
    if(i<200)
    {
        doubleList.enqueue(Y);
        i++;
    }
    else
    {
        doubleList.dequeue();
        doubleList.enqueue(Y);
    }
    updataChart();
}

void Widget::slotSliderPeriod(int num)
{
    ui->spinBox->setValue(num);
}

void Widget::slotSliderAmplitude(int num)
{
    ui->spinBox_2->setValue(num);
}

void Widget::slotSpinBoxPeriod(int num)
{
    m_period = num;
}

void Widget::slotSpinBoxAmplitude(int num)
{
    m_amplitude = 5*num/100.0;
}

void Widget::onSilderKpChanged(int value)
{
     ui->spinBoxKp->setValue(value / 200.0);
}

void Widget::onSilderKiChanged(int value)
{
     ui->spinBoxKi->setValue(value / 1000.0);
}

void Widget::onSilderKdChanged(int value)
{
    ui->spinBoxKd->setValue(value / 200.0);
}

void Widget::slotSetPID_p(double num)
{
    m_p1 = num;

    m_pid->setParams(m_p1,m_i1,m_d1);
}

void Widget::slotSetPID_i(double num)
{
    m_i1 = num;
    m_pid->setParams(m_p1,m_i1,m_d1);
}

void Widget::slotSetPID_d(double num)
{
    m_d1 = num;
    m_pid->setParams(m_p1,m_i1,m_d1);
}

