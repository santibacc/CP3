#ifndef RADAR_H
#define RADAR_H

#include <QWidget>
#include <qpaintbox.h>
#include <QPainter>

namespace Ui {
class Radar;
}

class Radar : public QWidget
{
    Q_OBJECT

public:
    explicit Radar(QWidget *parent = nullptr);
    ~Radar();
//signals:
//    void Points(uint32_t Punto);
private:
    Ui::Radar *ui;
    QPaintBox *QPaintBox1;
};

#endif // RADAR_H
