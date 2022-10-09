#ifndef QFORM1_H
#define QFORM1_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QInputDialog>
//#include <radar.h>
#include <qpaintbox.h>
#include <QPainter>
#include <math.h>

typedef union{
    uint8_t     u8[4];
    int8_t      i8[4];
    uint16_t    u16[2];
    int16_t     i16[2];
    uint32_t    u32;
    int32_t     i32;
}_work;


typedef union{
    uint8_t     u8[4];
    int32_t     i32;
}_work1;

typedef union{
    uint8_t     u8[2];
    uint16_t     u16;
}_work2;

QT_BEGIN_NAMESPACE
namespace Ui { class QForm1; }
QT_END_NAMESPACE

class QForm1 : public QMainWindow
{
    Q_OBJECT

public:

    QForm1(QWidget *parent = nullptr);
    ~QForm1();

private slots:
    void OnQTimer1();

    void OnRxChar();

    bool eventFilter(QObject *watched, QEvent *event) override;

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

//    void pasoPuntos (uint32_t Puntosradar);

    void on_DIRECT_clicked();

    void on_IRCONFIG_clicked();

private:
    Ui::QForm1 *ui;
    QTimer *QTimer1;
    QSerialPort *QSerialPort1;
//    Radar *radar;
    uint8_t rxBuf[256], header, nBytes, cks, index, tmoRX,LedsValue,LedstoAct,j;
    int8_t Ang;
    uint16_t negro1,negro2,negro3,blanco1,blanco2,blanco3;
    bool ok,BanRad=true,DirectOn=false,CONFIGIR=false;
    void SendCMD(uint8_t *buf, uint8_t length);
    _work w;
    _work1 w1;
    _work2 w2;
    void DecodeCmd(uint8_t *rxBuf);
    QPaintBox *QPaintBox1;
    void DrawRadar();
    void ActiveRadar(uint32_t R,uint32_t tita);
    void ActiveLine();
    void DirectComunication();

    typedef enum{
        ALIVE=0xF0,
        FIRMWARE=0xF1,
        LEDS=0x10,
        PULSADORES=0x12,
        TESTMOTORES=0xA1,
        SERVO=0xA2,
        DISTANCIA=0xA3,
        MOTORES=0xA4,
        NEGROIR=0xA6,
        BLANCOIR=0xA7,
        PANEO=0xA8,
        ACKNOWLEDGE=0x0D,
        SERVOSTOP=0x0A,
        UNKNOWNCOMANND=0xFF
    }_eIDCommand;
};
#endif // QFORM1_H
