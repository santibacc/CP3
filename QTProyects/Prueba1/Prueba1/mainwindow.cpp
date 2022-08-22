#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Qtimer1 = new QTimer(this);
    connect(Qtimer1, &QTimer::timeout,this,&MainWindow::onQtimer1);
//primer parametro objeto, segudndo de donde tomo la señal, tercero de donde la qiero recibir, cuarto que slot lo va a recibir
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Qtimer1;
}

void MainWindow::onQtimer1(){
    counter++;

    if(counter==20)
        counter=0;
    ui->pushButton_2->setText(QString("%1").arg(counter,2,10,QChar('0')));
}

void MainWindow::on_pushButton_clicked()
{
//    if(ui->pushButton->text() == "SI")
//        ui->pushButton->setText("NO");
//    else
//    ui->pushButton->setText("SI");

//    if(ui->pushButton_2->text() == "SI")
//        ui->pushButton_2->setText("NO");
//    else
//    ui->pushButton_2->setText("SI");

    if(Qtimer1->isActive()){

        Qtimer1->stop();
        ui->pushButton->setText("SI");
    }else
        counter=0;
    Qtimer1->start(1000);
    ui->pushButton->setText("NO");
}


void MainWindow::on_pushButton_2_clicked()
{
    int i;
    i= ui->pushButton_2->text().toInt();
    i++;
    ui->pushButton_2->setText(QString().number(i));
}

