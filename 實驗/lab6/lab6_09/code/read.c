#include <stdio.h>
#include <string.h>

#define MODULE_NAME "GPIO"

int main()
{
    char buf[1024] = "", path[] = "";

    sprintf(path, "/dev/%s", MODULE_NAME);
    FILE *fp = fopen(path, "w+");
    if(fp == NULL)
    {
        printf("can't open device!\n");
        return 0;
    }
    fread(buf, sizeof(buf), 1, fp);
    printf("%s", buf);
    fclose(fp);
    return 0;
}