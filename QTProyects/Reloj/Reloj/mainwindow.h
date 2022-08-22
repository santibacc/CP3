#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qpaintbox.h>
#include <QPainter>
#include <QDateTime>
#include <QTimer>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>

//qfile a file;
//qstring filename;
//en cpp
//para abirr un archi :filename=qfiledialog::getopenfilename(this,"open a file");
// nos devuele el nombre del archivo que se abrio
//tamalo del acrvhi osiemrpe en bites



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void Qtimer();
    void resizeevent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QTimer *QTimer1;
    QPaintBox *QPaintbox1;

};
#endif // MAINWINDOW_H
