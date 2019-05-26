#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "gpio.h"
using namespace std;

int times = 0;
int values[4] = {0, 0, 0, 0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;

// 可控制的接腳數量
const unsigned int numIO = 4;
// 接腳對應的名稱
const unsigned int IONames[numIO] = {160, 161, 162, 163};

void InitLed()
{
    for (int i = 0; i < 4; ++i)
    {
        ExportIO(i);
        SetIODir(i);
    }
}

void* SetLed1ValuebyMutex(void* arg)
{
    int index = 0;

    for (int i = 0; i < times; ++i)
    {

        pthread_mutex_lock(&mutex);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* SetLed2ValuebyMutex(void* arg)
{
    int index = 1;

    for (int i = 0; i < times; ++i)
    {

        pthread_mutex_lock(&mutex);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* SetLed3ValuebyMutex(void* arg)
{
    int index = 2;

    for (int i = 0; i < times; ++i)
    {

        pthread_mutex_lock(&mutex);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* SetLed4ValuebyMutex(void* arg)
{
    int index = 3;

    for (int i = 0; i < times; ++i)
    {

        pthread_mutex_lock(&mutex);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* SetLed1ValuebySema(void* arg)
{
    int index = 0;

    for (int i = 0; i < times; ++i)
    {

        sem_wait(&sem);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;
        sem_post(&sem);
        sleep(1);
    }
}

void* SetLed2ValuebySema(void* arg)
{
    int index = 1;

    for (int i = 0; i < times; ++i)
    {

        sem_wait(&sem);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;
        sem_post(&sem);
        sleep(1);
    }
}

void* SetLed3ValuebySema(void* arg)
{
    int index = 2;

    for (int i = 0; i < times; ++i)
    {

        sem_wait(&sem);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;
        sem_post(&sem);
        sleep(1);
    }
}

void* SetLed4ValuebySema(void* arg)
{
    int index = 3;

    for (int i = 0; i < times; ++i)
    {

        sem_wait(&sem);

        values[index] = !(bool(values[index]));
        SetIOValue(index, values[index]);
        cout << "thread-led" << index << ": "
             << "value is " << values[index] << endl;
        sem_post(&sem);
        sleep(1);
    }
}

int main(int argc, char* argv[])
{
    InitLed();

    string str;
    if (argc == 3)
    {
        for (int i = 0; i < 4; ++i)
            values[i] = argv[1][i] - '0';
        str = argv[2];
        times = stoi(str);
    }

    pthread_t threads[4];

    string mutexSema = "";

    cout << "m/s? ";
    cin >> mutexSema;

    if (mutexSema == "m")
    {
        cout << "mutex" << endl;
        pthread_create(&threads[0], NULL, SetLed1ValuebyMutex, NULL);
        pthread_create(&threads[1], NULL, SetLed2ValuebyMutex, NULL);
        pthread_create(&threads[2], NULL, SetLed3ValuebyMutex, NULL);
        pthread_create(&threads[3], NULL, SetLed4ValuebyMutex, NULL);
    }
    else
    {

        cout << "semaphore" << endl;
        pthread_create(&threads[0], NULL, SetLed1ValuebySema, NULL);
        pthread_create(&threads[1], NULL, SetLed2ValuebySema, NULL);
        pthread_create(&threads[2], NULL, SetLed3ValuebySema, NULL);
        pthread_create(&threads[3], NULL, SetLed4ValuebySema, NULL);
        sem_post(&sem);
    }


    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    return 0;
}
