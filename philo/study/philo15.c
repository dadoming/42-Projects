// This is a deadlock!

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexWater = PTHREAD_MUTEX_INITIALIZER;

int fuel = 50;
int water = 10;

/*

    The if statements in the routine function are written al contrair
    So it's very likely that they get stuck on waits.

*/


void *routine()
{
    if (rand() % 2 == 0)
    {
        pthread_mutex_lock(&mutexFuel);
        sleep(1);
        pthread_mutex_lock(&mutexWater);
    }
    else 
    {
        pthread_mutex_lock(&mutexWater);
        sleep(1);
        pthread_mutex_lock(&mutexFuel);
    }
    fuel += 50;
    water = fuel;
    printf("Incremented to: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexWater);
}

int main(void)
{
    pthread_t t[THREAD_NUM];
    // pthread_mutex_init(&mutexFuel, NULL); No need for this line
    int i = 0;
    while (i < THREAD_NUM)
    {
        if(pthread_create(&t[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if(pthread_join(t[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
    printf("Fuel: %d\n", fuel);
    printf("Water: %d\n", water);
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&mutexWater);
    return 0;
}