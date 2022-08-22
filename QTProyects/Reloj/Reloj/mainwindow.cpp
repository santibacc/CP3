#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer1=new QTimer(this);

    connect(QTimer1,&QTimer::timeout,this,&MainWindow::Qtimer);

    QPaintbox1 = new QPaintBox(0,0, ui->widget);

    QTimer1->start(100);
    resize(600, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete QTimer1;
    delete QPaintbox1;
}

void MainWindow::Qtimer(){

    QDateTime dt;
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintbox1->getCanvas());
    QRect boundingRect;
    QRect rect12(-20,-230,45,50);
    QRect rect6(-10,180,45,50);
    QRect rect3(200,-25,50,50);
    QRect rect9(-200,-25,50,50);
    QFont font =painter.font();
    float anglesec,anglehour,anglemin;
    int aux;
    dt=QDateTime().currentDateTime();

    if(dt.time().hour() >12)
        aux=dt.time().hour()-12;
    else
        aux=dt.time().hour();

 //   int side = qMin(width(), height());

    static const QPointF hourHand[3] = {
         QPoint(9, 10),
         QPoint(-9, 10),
         QPoint(0, -100)
     };
    static const QPointF minuteHand[3] = {
         QPoint(7, 8),
         QPoint(-7, 8),
         QPoint(0, -150)
     };

    static const QPointF secondHand[3] = {
         QPoint(5, 6),
         QPoint(-5, 6),
         QPoint(0, -200)
     };

    font.setPixelSize(40);
    painter.setFont(font);

    ui->statusbar->showMessage(dt.currentDateTime().toString("hh:mm:ss.zzz - dd/MM/yyyy"));

    pen.setWidth(5);
    pen.setColor(Qt::red);

    brush.setColor(Qt::black);
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

 //   painter.scale(width()/2, height()/2);

    painter.translate(ui->widget->width() / 2, ui->widget->height() / 2);

    painter.drawEllipse(QPointF(0,0),(ui->widget->width()/2)-5,(ui->widget->height()/2)-5);

    for(int i=0;i<60;i++){

        if((i%5)!=0){
            pen.setColor(Qt::red);
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(0,(ui->widget->height()/2)-20,0,(ui->widget->height()/2)-5);
        }else{
            pen.setColor(Qt::white);
            pen.setWidth(6);
            painter.setPen(pen);
            painter.drawLine(0,(ui->widget->height()/2)-50,0,(ui->widget->height()/2)-10);
        }
        painter.rotate(6);

    }

    painter.drawText(rect12,0,tr("12"), &boundingRect);
    painter.drawText(rect6,0,tr("6"), &boundingRect);
    painter.drawText(rect3,0,tr("3"), &boundingRect);
    painter.drawText(rect9,0,tr("9"), &boundingRect);

    brush.setColor(Qt::white);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.setBrush(brush);

  //  painter.rotate(30.0 * ((dt.currentDateTime() / 60.0)));

    anglesec=dt.time().second()*6+(dt.time().msec()/100)*0.6;
    painter.rotate(anglesec);
    painter.drawConvexPolygon(secondHand,3);

    anglemin=dt.time().minute()*6+(dt.time().second())*0.1;
    painter.rotate(anglemin-anglesec);
    painter.drawConvexPolygon(minuteHand,3);

    anglehour=aux*30+(dt.time().minute())*0.5;
    painter.rotate(anglehour-anglemin);
    painter.drawConvexPolygon(hourHand,3);

    painter.drawEllipse(QPointF(0,0),10,10); //centro

    QPaintbox1->update();
}

void MainWindow::resizeevent(QResizeEvent *event){

    QPaintbox1->resize(ui->widget->size());

}
