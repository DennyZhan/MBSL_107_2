/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lb_in;
    QLabel *label_2;
    QLabel *lb_out;
    QPushButton *open_camera;
    QPushButton *close_camera;
    QPushButton *grey;
    QPushButton *binery;
    QPushButton *masaic;
    QSlider *slider_masaic;
    QLabel *value_masaic;
    QPushButton *btn_pinhwa;
    QSlider *Slider_PinHwa;
    QLabel *PinHwa_Value;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lb_in = new QLabel(centralWidget);
        lb_in->setObjectName(QStringLiteral("lb_in"));
        lb_in->setGeometry(QRect(10, 10, 250, 250));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 360, 500, 500));
        lb_out = new QLabel(centralWidget);
        lb_out->setObjectName(QStringLiteral("lb_out"));
        lb_out->setGeometry(QRect(300, 10, 250, 250));
        open_camera = new QPushButton(centralWidget);
        open_camera->setObjectName(QStringLiteral("open_camera"));
        open_camera->setGeometry(QRect(10, 280, 101, 27));
        close_camera = new QPushButton(centralWidget);
        close_camera->setObjectName(QStringLiteral("close_camera"));
        close_camera->setGeometry(QRect(10, 320, 211, 91));
        grey = new QPushButton(centralWidget);
        grey->setObjectName(QStringLiteral("grey"));
        grey->setGeometry(QRect(230, 280, 101, 27));
        binery = new QPushButton(centralWidget);
        binery->setObjectName(QStringLiteral("binery"));
        binery->setGeometry(QRect(350, 280, 101, 27));
        masaic = new QPushButton(centralWidget);
        masaic->setObjectName(QStringLiteral("masaic"));
        masaic->setGeometry(QRect(470, 280, 161, 27));
        slider_masaic = new QSlider(centralWidget);
        slider_masaic->setObjectName(QStringLiteral("slider_masaic"));
        slider_masaic->setGeometry(QRect(470, 300, 160, 29));
        slider_masaic->setMinimum(1);
        slider_masaic->setMaximum(100);
        slider_masaic->setValue(1);
        slider_masaic->setOrientation(Qt::Horizontal);
        value_masaic = new QLabel(centralWidget);
        value_masaic->setObjectName(QStringLiteral("value_masaic"));
        value_masaic->setGeometry(QRect(470, 320, 67, 17));
        btn_pinhwa = new QPushButton(centralWidget);
        btn_pinhwa->setObjectName(QStringLiteral("btn_pinhwa"));
        btn_pinhwa->setGeometry(QRect(650, 280, 141, 27));
        Slider_PinHwa = new QSlider(centralWidget);
        Slider_PinHwa->setObjectName(QStringLiteral("Slider_PinHwa"));
        Slider_PinHwa->setGeometry(QRect(640, 300, 160, 29));
        Slider_PinHwa->setMinimum(1);
        Slider_PinHwa->setSingleStep(2);
        Slider_PinHwa->setOrientation(Qt::Horizontal);
        PinHwa_Value = new QLabel(centralWidget);
        PinHwa_Value->setObjectName(QStringLiteral("PinHwa_Value"));
        PinHwa_Value->setGeometry(QRect(650, 320, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lb_in->setText(QApplication::translate("MainWindow", "picture in", 0));
        label_2->setText(QApplication::translate("MainWindow", "picture in", 0));
        lb_out->setText(QApplication::translate("MainWindow", "picture out", 0));
        open_camera->setText(QApplication::translate("MainWindow", "open camera", 0));
        close_camera->setText(QApplication::translate("MainWindow", "close camera and save", 0));
        grey->setText(QApplication::translate("MainWindow", "grey", 0));
        binery->setText(QApplication::translate("MainWindow", "binery", 0));
        masaic->setText(QApplication::translate("MainWindow", "masaic", 0));
        value_masaic->setText(QApplication::translate("MainWindow", "1", 0));
        btn_pinhwa->setText(QApplication::translate("MainWindow", "MedianBlur", 0));
        PinHwa_Value->setText(QApplication::translate("MainWindow", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
