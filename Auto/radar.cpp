#include "radar.h"
#include "ui_radar.h"

Radar::Radar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Radar)
{
    ui->setupUi(this);
    QPaintBox1 = new QPaintBox(0, 0, ui->ActiveRadar);
}

Radar::~Radar()
{
    delete ui;
}

//void Radar::Points(uint32_t punto){

//    QPen pen;
//    QBrush brush;
//    QPainter painter(QPaintBox1->getCanvas());

//    pen.setWidth(2);
//    pen.setColor(Qt::cyan);

//    brush.setColor(Qt::yellow);
//    brush.setStyle(Qt::BrushStyle::SolidPattern);

//    painter.setPen(pen);
//    painter.setBrush(brush);

//    painter.drawEllipse(10,10,ui->ActiveRadar->width()-10,ui->ActiveRadar->height()-10);

//    QPaintBox1->update();

//}
