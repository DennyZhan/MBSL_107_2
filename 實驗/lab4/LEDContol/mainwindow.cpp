#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
using namespace std;


const int ledNum = 4;
const int leds[] = {190, 191, 192, 193};


int ioExport(unsigned int gpio)
{
    int fd, len;
    char buf[64];

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);

    close(fd);
    return 0;
}

int ioUnexport(unsigned int gpio)
{
    int fd, len;
    char buf[64];

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);

    close(fd);
    return 0;
}

int ioSetDir(unsigned int gpio, string dirStatus)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf),
        "/sys/class/gpio/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/direction");
        return fd;
    }

    if (dirStatus == "out")
        write(fd, "out", 4);
    else
        write(fd, "in", 3);

    close(fd);
    return 0;
}

int ioSetValue(unsigned int gpio, int value)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf),
        "/sys/class/gpio/gpio%d/value", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/set-value");
        return fd;
    }

    if (value == 0)
        write(fd, "0", 2);
    else
        write(fd, "1", 2);

    close(fd);
    return 0;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lb_onoffs.clear();
    lb_onoffs.push_back(ui->label_onoff1);
    lb_onoffs.push_back(ui->label_onoff2);
    lb_onoffs.push_back(ui->label_onoff3);
    lb_onoffs.push_back(ui->label_onoff4);

    checks.clear();
    checks.push_back(ui->checkBox_LED1);
    checks.push_back(ui->checkBox_LED2);
    checks.push_back(ui->checkBox_LED3);
    checks.push_back(ui->checkBox_LED4);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(500);

    times = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    static bool on12 = false;
    bool onoffs[ledNum];

    ui->label_times->setText(QString::number(times));
    if (times) {
        ui->label_isFlashing->setText("YES");
        if (!on12) {
            onoffs[0] = true;
            onoffs[1] = true;
            onoffs[2] = false;
            onoffs[3] = false;
            SetLEDState(onoffs);
        }
        else {
            onoffs[0] = false;
            onoffs[1] = false;
            onoffs[2] = true;
            onoffs[3] = true;
            SetLEDState(onoffs);
            times -= 1;
        }
        on12 = !on12;
    }
    else
        ui->label_isFlashing->setText("NO");
}

void MainWindow::SetLEDState(bool onoffs[ledNum])
{

    for (int i = 0; i < ledNum; ++i) {
        if (onoffs[i])
            lb_onoffs[i]->setText("ON");
        else
            lb_onoffs[i]->setText("OFF");
    }
}

void MainWindow::on_pushButton_1_pressed()
{
    ui->pushButton_1->setText("Hello!!!");
}

void MainWindow::on_pushButton_1_released()
{
    bool onoffs[ledNum];

    ui->pushButton_1->setText("Set LED State");
    for (int i = 0; i < ledNum; ++i) {
        ioExport(leds[i]);
        ioSetDir(leds[i], "out");

        if (checks[i]->checkState()) {
            onoffs[i] = true;
            ioSetValue(leds[i], 1);
        }
        else {
            onoffs[i] = false;
            ioSetValue(leds[i], 0);
        }
    }
    SetLEDState(onoffs);
}

void MainWindow::on_pushButton_2_pressed()
{
    ui->pushButton_2->setText("Hello!!!");
}

void MainWindow::on_pushButton_2_released()
{
    ui->pushButton_2->setText("LED Flash Alternately");
    times = ui->spinBox->value();
}
