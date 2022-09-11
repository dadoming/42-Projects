/* 
    Producer-Consumer    Problem

    1) Manage shared memory access
    2) Checking for if buffer is full
    3) Checing for if buffer is empty

*/

#include "sem.h"

#define THREAD_NUM 2

sem_t semEmpty;
sem_t semFull;

pthread_mutex_t mutexBuffer;

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;

void *producer(void* arg)
{
    while (1)
    {
        // Produce
        int x = rand() % 100; 

        // Add to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        buffer[count] = x;
        count++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

void *consumer(void* arg)
{
    while (1)
    {
        // Remove from the buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        int y = buffer[count - 1];
        count--;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);
        printf("Got %d\n", y);
    }
}

int main(void)
{
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer, NULL);
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);
    int i = 0;
    while (i < THREAD_NUM)
    {
        if(i % 2 == 0)
        {
            if(pthread_create(&th[i], 0, &producer, 0) != 0)
                return (1);
        }
        else
        {
            if(pthread_create(&th[i], 0, &consumer, 0) != 0)
                return (1);
        }
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if(pthread_join(th[i], 0) != 0)
            return (2);
        i++;
    }
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);
    return (0);
}