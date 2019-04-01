#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_1_pressed();

    void on_pushButton_1_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void update();

private:
    int times;
    Ui::MainWindow *ui;
    QVector<QCheckBox*> checks;
    QVector<QLabel*> lb_onoffs;
    QTimer *timer;
    void SetLEDState(bool onoffs[]);

};

#endif // MAINWINDOW_H
