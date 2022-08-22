#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer1=new QTimer(this);
    connect(QTimer1, &QTimer::timeout,this,&MainWindow::on_QTimer1);

    ui->MS->display(QString("%1").arg(0,2,10,QChar('0')));
    ui->SEG->display(QString("%1").arg(0,2,10,QChar('0')));
    ui->MIN->display(QString("%1").arg(0,2,10,QChar('0')));

}
MainWindow::~MainWindow()
{
    delete ui;
    delete QTimer1;
}

void MainWindow::on_QTimer1(){

    counter++;

    if(!PAUSA){
        ui->MS->display(QString("%1").arg(counter%10,2,10,QChar('0')));
        ui->SEG->display(QString("%1").arg((counter/10)%60,2,10,QChar('0')));
        ui->MIN->display(QString("%1").arg((counter/600)%60,2,10,QChar('0')));
    }
}

void MainWindow::on_STARTBUTTON_clicked()
{
    QTimer1->start(100);
    PAUSA=0;

}

void MainWindow::on_STOPBUTTON_clicked()
{
    QTimer1->stop();
}


void MainWindow::on_PAUSEBUTTON_clicked()
{
    PAUSA=1;
}


void MainWindow::on_RESET_clicked()
{
    counter=0;
    ui->MS->display(QString("%1").arg(0,2,10,QChar('0')));
    ui->SEG->display(QString("%1").arg(0,2,10,QChar('0')));
    ui->MIN->display(QString("%1").arg(0,2,10,QChar('0')));
}


void MainWindow::on_LAP_clicked()
{
 //  ui->plainTextEdit->insertPlainText(QString("LAP %1 = ").arg((counter2),2,10,QChar('0')));
   ui->plainTextEdit->insertPlainText(QString("%1").arg((counter/600)%60,2,10,QChar('0')));
   ui->plainTextEdit->insertPlainText(QString(":%1").arg((counter/10)%60,2,10,QChar('0')));
   ui->plainTextEdit->insertPlainText(QString(":%1\n").arg(counter%10,2,10,QChar('0')));
 //  counter2++;
}

