#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDateTime>
#include <QTimer>
#include <QStyle>
#include <QDebug>
#include <qpaintbox.h>
#include <stdlib.h>
#include <QFile>
#include <QFileDialog>
#include <QRandomGenerator>
#include <iostream>
#include <math.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    void paintEvent(QPaintEvent *event) override;

private slots:

    void Qtimer();
    void OnQPaintBox1MousePress(QMouseEvent *event);

    void on_START_clicked();

    void on_STOP_clicked();

    void on_RESTART_clicked();
    /**
     * @brief SAVEHeader
     * crea la cabecera del archivo
     */
    void SAVEHeader();
    /**
     * @brief DRAW
     * @param a     que topo se genera (1-4) colores , 5 gris
     * @param c     pasa la posicion pra pintar el topo gris (1-4)
     */
    void DRAW(int a,int c);
    /**
     * @brief NewTime
     * @param n         parametro para decirle a que topo tengo que generarle nuevo tiempo
     */
    void NewTime(int n);
    /**
     * @brief SAVEInfo Sirve para guardar en el archivo la info de cada topo
     * @param a         parametro para decirle la info de que topo se va a guardar(0-3)+1
     */
    void SAVEInfo(int a,int score);
private:
    Ui::MainWindow *ui;
    QTimer *QTimer1;
    QPaintBox *QPaintbox1;
    QDateTime dt;
    QString fileName;

    typedef struct{

        uint32_t timeoutside;
        uint32_t timetoshow;
        uint32_t usertimereaction;
        uint32_t currenttime;

    }_sTop;

    _sTop mitopo[4];

    int mousePosX, mousePosY;
    uint32_t counter=0;
    int counter2=0;
    bool START,STOP,PLAYING,END;
    int cen;
    int radio=40;
    int x,y;
    int hit=0,fail=0,error=0;
    int32_t score=0;

};
#endif // MAINWINDOW_H
