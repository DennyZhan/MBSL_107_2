#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;


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

int main(int argc, char* argv[])
{
    int num = 0, gpios[] = {160, 161, 162, 163};
    string arg1, arg2;
    
    cout << "初始化中..." << endl;
    for (int i = 0; i < 4; i++) {
        ioExport(gpios[i]);
        ioSetDir(gpios[i], "out");
        ioSetValue(gpios[i], 1);
    }
    sleep(1);
    for (int i = 0; i < 4; i++) {
        ioSetValue(gpios[i], 0);
    }

    cout << "正在分析輸入參數..." << endl;
    sleep(1);
    if (argc == 3) {
        arg1.assign(argv[1]);
        arg2.assign(argv[2]);

        if (arg1 == "Mode_Shine") {
            for (int i = 0; i < int(arg2); i++) {
                cout << "LED1, LED2 亮" << endl;
                ioSetValue(gpios[0], 0);
                ioSetValue(gpios[1], 0);
                ioSetValue(gpios[1], 1);
                ioSetValue(gpios[2], 1);
                sleep(1);
                cout << "LED3, LED4 亮" << endl;
                ioSetValue(gpios[0], 1);
                ioSetValue(gpios[1], 1);
                ioSetValue(gpios[1], 0);
                ioSetValue(gpios[2], 0);
            }
        }
        else {
            if (arg1 == "LED1")
                num = 0;
            else if (arg1 == "LED2")
                num = 1;
            else if (arg1 == "LED3")
                num = 2;
            else
                num = 3;
            if (arg2 == "out")
                ioSetValue(gpios[num], 1);
        }
    }

    cout << "正在結束程式..." << endl;
    for (int i = 0; i < 4; i++) {
        ioExport(gpios[i]);
        ioSetDir(gpios[i], "out");
        ioSetValue(gpios[i], 1);
    }
    sleep(1);
    for (int i = 0; i < 4; i++) {
        ioSetValue(gpios[i], 0);
        ioUnexport(gpios[i]);
    }
    

    return 0;
}