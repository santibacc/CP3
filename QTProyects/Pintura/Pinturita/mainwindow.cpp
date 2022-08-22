#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer1=new QTimer(this);

    connect(QTimer1,&QTimer::timeout,this,&MainWindow::Qtimer);

    QPaintbox1 = new QPaintBox(0,0, ui->LIENZO);

    QTimer1->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LINE_clicked()
{
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintbox1->getCanvas());

    pen.setWidth(3);
    pen.setColor(Qt::red);

    painter.setPen(pen);

    painter.drawLine(0, ui->LIENZO->height()/2,ui->LIENZO->width(),ui->LIENZO->height()/2);

    QPaintbox1->update(); //estaba dibujando en memoria, con el upfate dibujo en la pantalla
}


void MainWindow::on_pushButton_clicked()
{
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintbox1->getCanvas());

    pen.setWidth(2);
    pen.setColor(Qt::cyan);

    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawEllipse(10,10,ui->LIENZO->width()-10,ui->LIENZO->height()-10);

    QPaintbox1->update();
}

void MainWindow::Qtimer(){

    QDateTime dt;

    ui->statusBar->showMessage(dt.currentDateTime().toString("hh:mm:ss.zzz - dd/MM/yyyy"));

}
