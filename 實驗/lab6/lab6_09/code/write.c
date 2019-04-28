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
	printf("G9\n");
    for (i = 1; i < argc; ++i) {
	//decide LED
	if(argv[i][3] == '1')
	    strcat(buf, "0");
	else if(argv[i][3] == '2')
	    strcat(buf,"1");
	else if(argv[i][3] == '3')
	    strcat(buf,"2");
	else if(argv[i][3] == '4')
	    strcat(buf,"3");
	
	//decide On&Off
	if(argv[i][1] == 'n')
	    strcat(buf,"1");
	else if(argv[i][1] == 'f')
	    strcat(buf,"0");

        strcat(buf, " ");
	}
    fwrite(buf, sizeof(buf), 1, fp);

    fclose(fp);
    return 0;
}

