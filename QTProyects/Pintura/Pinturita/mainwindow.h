#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpaintbox.h>
#include <QPainter>
#include <QDateTime>
#include <QTimer>

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

    void on_LINE_clicked();

    void on_pushButton_clicked();

    void Qtimer();

private:
    Ui::MainWindow *ui;

    QTimer *QTimer1;
    QPaintBox *QPaintbox1;
};
#endif // MAINWINDOW_H
