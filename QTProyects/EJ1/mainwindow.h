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
    void OnQTimer1();

    void on_buttonStart_clicked();

    void on_buttonPause_clicked();

    void on_buttonReset_clicked();

    void on_buttonStop_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *QTimer1;

    int counter;

    bool pausa;

};
#endif // MAINWINDOW_H
