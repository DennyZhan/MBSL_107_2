#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *data;
    long m, n;

    printf("你好\n\n");
    printf("嗨\n");
    printf("Hi\n\n");

    data = getenv("QUERY_STRING");

    char myContent[128];

    if (strstr(data, "V1")) {
        sscanf(data, "R1=V1&T1=$[a-zA-Z0-9]&B1=Submit" ,&myContent);
        printf("<h1> 選項: 姓名</h1>");
        printf("<h2> 內容: %s</h2>" ,myContent);
    }
    else if (strstr(data, "V2")){
        sscanf(data, "R1=V2&T1=$[a-zA-Z0-9]&B1=Submit" ,&myContent);
        printf("<h1> 選項: 學號</h1>");
        printf("<h2> 內容: %s</h2>" ,myContent);
    }
    else {
        printf("你好");
    }

    printf("掰掰\n");

    exit(0);
}