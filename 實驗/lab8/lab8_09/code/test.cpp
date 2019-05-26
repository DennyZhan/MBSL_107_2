#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void* child(void* data, void* data2) {
    char* str = (char*) data;
    for(int i = 0; i < 3; ++i) {
        cout << str << endl;
        sleep(1);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t;
    char* str = "Child";
    pthread_create(&t, NULL, child, str, str);

    for (int i = 0; i < 3; ++i) {
        cout << "Master" << endl;
        sleep(1);
    }

    pthread_join(t, NULL);

    return 0;
}
