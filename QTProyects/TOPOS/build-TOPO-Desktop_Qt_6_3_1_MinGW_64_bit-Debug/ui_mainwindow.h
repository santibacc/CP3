/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *START;
    QPushButton *STOP;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *STATUS;
    QPushButton *RESTART;
    QLabel *ACIERTOS;
    QLabel *FALLOS;
    QLabel *ERROES;
    QLabel *SCORE;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(763, 400);
        MainWindow->setMaximumSize(QSize(800, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 741, 141));
        START = new QPushButton(centralwidget);
        START->setObjectName(QString::fromUtf8("START"));
        START->setGeometry(QRect(10, 160, 100, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("BankGothic Md BT")});
        font.setPointSize(12);
        START->setFont(font);
        STOP = new QPushButton(centralwidget);
        STOP->setObjectName(QString::fromUtf8("STOP"));
        STOP->setGeometry(QRect(10, 200, 100, 30));
        STOP->setMinimumSize(QSize(100, 0));
        STOP->setFont(font);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(640, 320, 121, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 320, 111, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("BankGothic Md BT")});
        font1.setPointSize(20);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 300, 121, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("BankGothic Md BT")});
        font2.setPointSize(18);
        label_2->setFont(font2);
        STATUS = new QLabel(centralwidget);
        STATUS->setObjectName(QString::fromUtf8("STATUS"));
        STATUS->setGeometry(QRect(130, 300, 361, 31));
        STATUS->setFont(font2);
        RESTART = new QPushButton(centralwidget);
        RESTART->setObjectName(QString::fromUtf8("RESTART"));
        RESTART->setGeometry(QRect(10, 240, 100, 30));
        RESTART->setFont(font);
        ACIERTOS = new QLabel(centralwidget);
        ACIERTOS->setObjectName(QString::fromUtf8("ACIERTOS"));
        ACIERTOS->setGeometry(QRect(160, 190, 150, 30));
        ACIERTOS->setFont(font);
        FALLOS = new QLabel(centralwidget);
        FALLOS->setObjectName(QString::fromUtf8("FALLOS"));
        FALLOS->setGeometry(QRect(160, 220, 150, 30));
        FALLOS->setFont(font);
        ERROES = new QLabel(centralwidget);
        ERROES->setObjectName(QString::fromUtf8("ERROES"));
        ERROES->setGeometry(QRect(160, 160, 150, 30));
        ERROES->setFont(font);
        SCORE = new QLabel(centralwidget);
        SCORE->setObjectName(QString::fromUtf8("SCORE"));
        SCORE->setGeometry(QRect(450, 190, 311, 41));
        SCORE->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        START->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        STOP->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TIME :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "STATUS:", nullptr));
        STATUS->setText(QString());
        RESTART->setText(QCoreApplication::translate("MainWindow", "RESTART", nullptr));
        ACIERTOS->setText(QCoreApplication::translate("MainWindow", "ACIERTOS: 0", nullptr));
        FALLOS->setText(QCoreApplication::translate("MainWindow", "FALLOS    : 0", nullptr));
        ERROES->setText(QCoreApplication::translate("MainWindow", "ERRORES :", nullptr));
        SCORE->setText(QCoreApplication::translate("MainWindow", "PUNTAJE: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
