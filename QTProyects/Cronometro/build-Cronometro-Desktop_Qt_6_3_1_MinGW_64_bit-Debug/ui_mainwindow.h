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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *MIN;
    QLCDNumber *SEG;
    QLCDNumber *MS;
    QLabel *label;
    QLabel *label_2;
    QPushButton *STARTBUTTON;
    QPushButton *STOPBUTTON;
    QPushButton *PAUSEBUTTON;
    QPushButton *RESET;
    QPlainTextEdit *plainTextEdit;
    QPushButton *LAP;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(633, 422);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 0, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(0, 0, 158, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 0, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(85, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(0, 0, 84, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(208, 208, 208, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        QBrush brush10(QColor(64, 65, 66, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        QBrush brush11(QColor(227, 227, 227, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        QBrush brush12(QColor(160, 160, 160, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        QBrush brush13(QColor(255, 51, 51, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        QBrush brush14(QColor(46, 47, 48, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        QBrush brush15(QColor(105, 105, 105, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        QBrush brush16(QColor(53, 54, 55, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MIN = new QLCDNumber(centralwidget);
        MIN->setObjectName(QString::fromUtf8("MIN"));
        MIN->setGeometry(QRect(140, 170, 100, 50));
        MIN->setFrameShape(QFrame::Box);
        MIN->setFrameShadow(QFrame::Raised);
        SEG = new QLCDNumber(centralwidget);
        SEG->setObjectName(QString::fromUtf8("SEG"));
        SEG->setGeometry(QRect(270, 170, 100, 50));
        SEG->setFrameShape(QFrame::Box);
        SEG->setFrameShadow(QFrame::Raised);
        MS = new QLCDNumber(centralwidget);
        MS->setObjectName(QString::fromUtf8("MS"));
        MS->setGeometry(QRect(400, 170, 100, 50));
        MS->setFrameShape(QFrame::Box);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 150, 16, 61));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 150, 61, 61));
        label_2->setFont(font);
        STARTBUTTON = new QPushButton(centralwidget);
        STARTBUTTON->setObjectName(QString::fromUtf8("STARTBUTTON"));
        STARTBUTTON->setGeometry(QRect(140, 100, 100, 50));
        QPalette palette1;
        QBrush brush17(QColor(255, 0, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush17);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush17);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        QBrush brush18(QColor(10, 33, 33, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        STARTBUTTON->setPalette(palette1);
        QFont font1;
        font1.setPointSize(15);
        STARTBUTTON->setFont(font1);
        STOPBUTTON = new QPushButton(centralwidget);
        STOPBUTTON->setObjectName(QString::fromUtf8("STOPBUTTON"));
        STOPBUTTON->setGeometry(QRect(270, 100, 100, 50));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush17);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        STOPBUTTON->setPalette(palette2);
        STOPBUTTON->setFont(font1);
        PAUSEBUTTON = new QPushButton(centralwidget);
        PAUSEBUTTON->setObjectName(QString::fromUtf8("PAUSEBUTTON"));
        PAUSEBUTTON->setGeometry(QRect(400, 100, 100, 50));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        PAUSEBUTTON->setPalette(palette3);
        PAUSEBUTTON->setFont(font1);
        RESET = new QPushButton(centralwidget);
        RESET->setObjectName(QString::fromUtf8("RESET"));
        RESET->setGeometry(QRect(270, 240, 100, 50));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        RESET->setPalette(palette4);
        RESET->setFont(font1);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(60, 239, 181, 111));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush19(QColor(170, 255, 127, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush19);
        QBrush brush20(QColor(212, 255, 127, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush20);
        QBrush brush21(QColor(191, 255, 63, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush21);
        QBrush brush22(QColor(85, 127, 0, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush22);
        QBrush brush23(QColor(113, 170, 0, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush23);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush19);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush19);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush20);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush19);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush19);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush19);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush19);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush20);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush23);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush19);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush19);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        plainTextEdit->setPalette(palette5);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));
        LAP = new QPushButton(centralwidget);
        LAP->setObjectName(QString::fromUtf8("LAP"));
        LAP->setGeometry(QRect(270, 300, 100, 50));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush17);
        QBrush brush24(QColor(255, 127, 127, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush24);
        QBrush brush25(QColor(255, 63, 63, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush25);
        QBrush brush26(QColor(127, 0, 0, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush26);
        QBrush brush27(QColor(170, 0, 0, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush27);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush17);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush17);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush16);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush26);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush24);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush25);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush26);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush27);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush26);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush26);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        LAP->setPalette(palette6);
        LAP->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        STARTBUTTON->setText(QCoreApplication::translate("MainWindow", "START ", nullptr));
        STOPBUTTON->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        PAUSEBUTTON->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        RESET->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        LAP->setText(QCoreApplication::translate("MainWindow", "LAP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
