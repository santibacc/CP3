#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_STARTBUTTON_clicked();

    void on_QTimer1();

    void on_STOPBUTTON_clicked();

    void on_PAUSEBUTTON_clicked();

    void on_RESET_clicked();

    void on_LAP_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *QTimer1;
    int counter;
  //  int counter2;
    char PAUSA;
};
#endif // MAINWINDOW_H
