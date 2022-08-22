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

    connect(QPaintbox1, &QPaintBox::OnMousePress, this, &MainWindow::OnQPaintBox1MousePress);

    srand(time(nullptr));
    START=false;
    QTimer1->start(10);

    for(int i=0;i<4;i++){
        NewTime(i);
        mitopo[i].currenttime=0;
        mitopo[i].usertimereaction=0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete QTimer1;
    delete QPaintbox1;
}

void MainWindow::Qtimer(){

    ui->statusbar->showMessage(dt.currentDateTime().toString("hh:mm:ss - dd/MM/yyyy"));

    if(START==true){
        counter2++;
        ui->STATUS->setText(QString("GAME STARTS IN %1").arg(5-(counter2/100),2,10,QChar('0')));
    }else{

        for(int i=1;i<5;i++)
            DRAW(5,i);
    }

    if((counter2/100)==5){
        PLAYING=true;
    }

    if(PLAYING==true){

        START=false;
        counter++;
        mitopo[0].currenttime++;
        mitopo[1].currenttime++;
        mitopo[2].currenttime++;
        mitopo[3].currenttime++;

        ui->lcdNumber->display(QString("%1").arg(30-(counter/100),2,10,QChar('0')));
        ui->STATUS->setText("PLAYING");

        if( mitopo[0].currenttime>=(mitopo[0].timetoshow)/10)
            DRAW(1,0);
        if((mitopo[0].timetoshow+mitopo[0].timeoutside)/10<=mitopo[0].currenttime){
            DRAW(5,1);
            mitopo[0].currenttime=0;
            NewTime(0);
            error++;
            score-=10;
            SAVEInfo(0,score);
        }

        if( mitopo[1].currenttime>=(mitopo[1].timetoshow)/10)
            DRAW(2,0);
        if((mitopo[1].timetoshow+mitopo[1].timeoutside)/10<=mitopo[1].currenttime){
            DRAW(5,2);
            mitopo[1].currenttime=0;
            NewTime(1);
            error++;
            score-=10;
            SAVEInfo(1,score);
       }

        if( mitopo[2].currenttime>=(mitopo[2].timetoshow)/10)
            DRAW(3,0);
        if((mitopo[2].timetoshow+mitopo[2].timeoutside)/10<=mitopo[2].currenttime){
            DRAW(5,3);
            mitopo[2].currenttime=0;
            NewTime(2);
            error++;
            score-=10;
            SAVEInfo(2,score);
        }

        if( mitopo[3].currenttime>=(mitopo[3].timetoshow)/10)
            DRAW(4,0);
        if((mitopo[3].timetoshow+mitopo[3].timeoutside)/10<=mitopo[3].currenttime){
            DRAW(5,4);
            mitopo[3].currenttime=0;
            NewTime(3);
            error++;
            score-=10;
            SAVEInfo(3,score);
        }
        ui->ERROES->setText(QString("ERRORES: %1").arg(error,1,10,QChar('0')));
        ui->SCORE->setText(QString("SCORE: %1").arg(score,3,10,QChar('0')));
    }

    if((counter/100)>=30){

         END=true;
         ui->STATUS->setText("GAME HAS ENDED");
         QTimer1->stop();

    }

    if(END==true){

        ui->lcdNumber->display(QString("%1").arg(0,2,10,QChar('0')));
        PLAYING=false;
        for(int i=1;i<5;i++)
            DRAW(5,i);
        SAVEInfo(1,1);
    }

}
void MainWindow::on_START_clicked()
{
    SAVEHeader();
    START=true;
    QTimer1->start(10);
    END=false;
}
void MainWindow::on_STOP_clicked()
{
    QTimer1->stop();
    STOP=true;
}
void MainWindow::on_RESTART_clicked()
{
    if(PLAYING==false){
        counter=0;
        counter2=0;
        START=false;
        ui->STATUS->setText("PRESS START");
        score=0;
        error=0;
        hit=0;
        fail=0;
        ui->ERROES->setText(QString("ERRORES: %1").arg(error,1,10,QChar('0')));
        ui->SCORE->setText(QString("SCORE: %1").arg(score,3,10,QChar('0')));
        ui->ACIERTOS->setText(QString("ACIERTOS: %1").arg(hit,1,10,QChar('0')));
        ui->FALLOS->setText(QString(  "FALLOS    : %1").arg(fail,1,10,QChar('0')));
    }
}
void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    static bool first = true;

    if(first){
        first = false;
        QPainter paint(QPaintbox1->getCanvas());
    }
}
void MainWindow::OnQPaintBox1MousePress(QMouseEvent *event){

    mousePosX = event->pos().x();
    mousePosY = event->pos().y();

    if(event->button() == Qt::MouseButton::LeftButton){

        if ((QPaintbox1->getCanvas()->toImage().pixelColor(mousePosX, mousePosY) == Qt::gray)&& PLAYING==true){
            fail++;
            score-=20;
        }
        if (QPaintbox1->getCanvas()->toImage().pixelColor(mousePosX, mousePosY) == Qt::red){
            hit++;
            mitopo[0].usertimereaction=(mitopo[0].currenttime)*10-mitopo[0].timetoshow;
            score+=((pow(2000,2))/(mitopo[0].timeoutside*mitopo[0].usertimereaction));
            mitopo[0].currenttime=0;
            DRAW(5,1);
            NewTime(0);
            SAVEInfo(0,score);
        }
        if (QPaintbox1->getCanvas()->toImage().pixelColor(mousePosX, mousePosY) == Qt::green){
            hit++;
            mitopo[1].usertimereaction=(mitopo[1].currenttime)*10-mitopo[1].timetoshow;
            score+=((pow(2000,2))/(mitopo[1].timeoutside*mitopo[1].usertimereaction));
            mitopo[1].currenttime=0;
            DRAW(5,2);
            NewTime(1);
            SAVEInfo(1,score);
        }
        if (QPaintbox1->getCanvas()->toImage().pixelColor(mousePosX, mousePosY) == Qt::yellow){
            hit++;
            mitopo[2].usertimereaction=(mitopo[2].currenttime)*10-mitopo[2].timetoshow;
            score+=((pow(2000,2))/(mitopo[2].timeoutside*mitopo[2].usertimereaction));
            mitopo[2].currenttime=0;
            DRAW(5,3);
            NewTime(2);
            SAVEInfo(2,score);
        }
        if (QPaintbox1->getCanvas()->toImage().pixelColor(mousePosX, mousePosY) == Qt::blue){
            hit++;
            mitopo[3].usertimereaction=(mitopo[3].currenttime)*10-mitopo[3].timetoshow;
            score+=((pow(2000,2))/(mitopo[3].timeoutside*mitopo[3].usertimereaction));
            mitopo[3].currenttime=0;
            DRAW(5,4);
            NewTime(3);
            SAVEInfo(3,score);
        }
    }
    ui->ACIERTOS->setText(QString("ACIERTOS: %1").arg(hit,1,10,QChar('0')));
    ui->FALLOS->setText(QString(  "FALLOS    : %1").arg(fail,1,10,QChar('0')));
}
void MainWindow::NewTime(int n){//n = para que topo generar nuevos tiempos

    mitopo[n].timetoshow= (rand()%5000)+1000;
    mitopo[n].timeoutside=(rand()%1500)+500;

}
void MainWindow::DRAW(int a,int c){ //a es que topo pintar (5 topo gris), c es el lugar para poner el topo gris

    QPen pen;
    QBrush brush;
    QPainter painter(QPaintbox1->getCanvas());

    cen=(ui->widget->width()/5);
    radio=40;

    pen.setWidth(5);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

        switch(a){
            case 1:

                brush.setColor(Qt::red);
                brush.setStyle(Qt::BrushStyle::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(QPointF(cen,ui->widget->height()/2),radio,radio);

            break;
            case 2:

                brush.setColor(Qt::green);
                brush.setStyle(Qt::BrushStyle::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(QPointF(cen*2,ui->widget->height()/2),radio,radio);

            break;
            case 3:

                brush.setColor(Qt::yellow);
                brush.setStyle(Qt::BrushStyle::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(QPointF(cen*3,ui->widget->height()/2),radio,radio);

            break;
            case 4:

                brush.setColor(Qt::blue);
                brush.setStyle(Qt::BrushStyle::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(QPointF(cen*4,ui->widget->height()/2),radio,radio);

            break;
            case 5:

                brush.setColor(Qt::gray);
                brush.setStyle(Qt::BrushStyle::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(QPointF(cen*c,ui->widget->height()/2),radio,radio);

            break;
    }
    QPaintbox1->update();
}
void MainWindow::SAVEHeader(){

    QFile aFile;

    QDateTime dt= QDateTime().currentDateTime();
    char str[20];

    fileName = QFileDialog::getSaveFileName(this,"NAME & SAVE THE FILE","PRUEBA1",tr("*.txt"));
    aFile.setFileName(fileName);

     if(!aFile.open(QIODevice::ReadWrite)){
         ui->STATUS->setText("FILE ERROR!!");
         return;
     }else{

         aFile.flush();
         sprintf(str,"HEADER\tM48\n");
         aFile.write(str,strlen(str));

         sprintf(str,"\nDAY:\t%d\n",dt.date().day());
         aFile.write(str,strlen(str));

         sprintf(str,"MONTH:\t%d\n",dt.date().month());
         aFile.write(str,strlen(str));

         sprintf(str,"YEAR:\t%d\n/\n",dt.date().year());
         aFile.write(str,strlen(str));

         sprintf(str,"HOURS:\t%d\n",dt.time().hour());
         aFile.write(str,strlen(str));

         sprintf(str,"MINUTES:\t%d\n",dt.time().minute());
         aFile.write(str,strlen(str));

         sprintf(str,"SECONDS:\t%d\n",dt.time().second());
         aFile.write(str,strlen(str));

         sprintf(str,"\nEND HEADER\tM50\n");
         aFile.write(str,strlen(str));

         sprintf(str,"\nSTART DATA\t:\n");
         aFile.write(str,strlen(str));

         aFile.close();
     }
}
void MainWindow::SAVEInfo(int a,int score){

    QFile aFile;
    char str[30];

    aFile.setFileName(fileName);
    if(!aFile.open(QIODevice::ReadWrite)){
        ui->STATUS->setText("FILE ERROR!!");
        return;
    }else{

        aFile.seek(aFile.size()); //me voy al final del archivo

        if(!END){
            sprintf(str,"\nMOLE NUMBER: \t%d\n",a+1);
            aFile.write(str,strlen(str));
            sprintf(str,"TIME TO SHOW: \t%d\n",mitopo[a].timetoshow);
            aFile.write(str,strlen(str));
            sprintf(str,"TIME OUTSIDE: \t%d\n",mitopo[a].timeoutside);
            aFile.write(str,strlen(str));
            sprintf(str,"USERTIME REACTION: \t%d\n",mitopo[a].usertimereaction);
            aFile.write(str,strlen(str));
            sprintf(str,"SCORE: \t%d\n",score);
            aFile.write(str,strlen(str));
            sprintf(str,"REMAINED TIME(MS): \t%d\n",(mitopo[a].timeoutside-mitopo[a].usertimereaction));
            aFile.write(str,strlen(str));
        }else{
            sprintf(str,"\nEND FILE\tM30\n");
            aFile.write(str,strlen(str));
        }
        aFile.close();
    }
}
