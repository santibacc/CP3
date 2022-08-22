#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout,this,&MainWindow::OnQTimer1);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete QTimer1;
}


void MainWindow::OnQTimer1(){
    counter++;
    QString str;
       //ui->lcdNumber->setText(QString("%1").arg(counter,2,10,QChar('0')));
    if (!pausa){
         ui->lcdNumber_3->display(counter%100);
         ui->lcdNumber_2->display(QString("%1").arg(((counter/100)%60),2,10,QChar('0')));
         ui->lcdNumber->display(QString("%1").arg(((counter/6000)%60),2,10,QChar('0')));
    }
}

void MainWindow::on_buttonStart_clicked()
{
    QTimer1->start(10);
}


void MainWindow::on_buttonPause_clicked()
{
    if (!pausa)
        pausa = true;
    else
        pausa = false;
}


void MainWindow::on_buttonReset_clicked()
{
    counter = 0;
}


void MainWindow::on_buttonStop_clicked()
{
    QTimer1->stop();
}


void MainWindow::on_pushButton_clicked()
{
    if (QTimer1->isActive()){
        ui->plainTextEdit->insertPlainText(QString("%2:").arg(((counter/6000)%60),2,10,QChar('0')));
        ui->plainTextEdit->insertPlainText(QString("%2:").arg(((counter/100)%60),2,10,QChar('0')));
        ui->plainTextEdit->insertPlainText(QString("%2").arg(((counter/10)%100),2,10,QChar('0')));
    }
}

