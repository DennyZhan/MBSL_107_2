#include <stdio.h>
#include <string.h>

#define MODULE_NAME "GPIO"

int main(int argc, char *argv[])
{
    char buf[1024] = "", path[] = "";
    int i = 0;

    sprintf(path, "/dev/%s", MODULE_NAME);
    FILE *fp = fopen(path, "w+");
    if(fp == NULL)
    {
        printf("can't open device!\n");
        return 0;
    }

    for (i = 0; i < argc; ++i)
        strcat(buf, argv[i]);
    fwrite(buf, sizeof(buf), 1, fp);

    fclose(fp);
    return 0;
}


