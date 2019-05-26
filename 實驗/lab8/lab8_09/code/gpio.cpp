#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "gpio.h"

int ExportIO(unsigned int index)
{
    int fd = 0, len = 0;
    char buf[64];

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", IONames[index]);
    write(fd, buf, len);

    close(fd);
    return 0;
}

int UnexportIO(unsigned int index)
{
    int fd, len;
    char buf[64];

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", IONames[index]);
    write(fd, buf, len);

    close(fd);
    return 0;
}

int SetIODir(unsigned int index, int inout)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf),
        "/sys/class/gpio/gpio%d/direction", IONames[index]);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/direction");
        return fd;
    }

    if (inout)
        write(fd, "out", 4);
    else
        write(fd, "in", 3);

    close(fd);
    return 0;
}


int SetIOValue(unsigned int index, int value)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf),
        "/sys/class/gpio/gpio%d/value", IONames[index]);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio/set-value");
        return fd;
    }

    if (value)
        write(fd, "1", 2);
    else
        write(fd, "0", 2);

    close(fd);
    return 0;
}
