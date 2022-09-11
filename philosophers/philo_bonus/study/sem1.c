// Example of 16 people login queue

#include "sem.h"

#define THREAD_NUM 16
sem_t semaphore;

void *routine(void *arg)
{
    printf("[%d] Waiting in the login queue...\n", *(int*)arg);
    sem_wait(&semaphore);
    printf("[%d] Logged in!\n", *(int*)arg);
    sleep(rand() % 5+1); // The user stays online for a random amount of time
    printf("[%d] Logged out!\n", *(int*)arg);
    sem_post(&semaphore);
    free(arg);
}

int main(void)
{
    pthread_t th[THREAD_NUM];
    //sem_init(&semaphore, 0, 3);     ==      semaphore.__align = 2; 
    sem_init(&semaphore, 0, 20);
    int i = 0;
    while (i < THREAD_NUM)
    {
        int *a = malloc (sizeof(int));
        *a = i;
        if(pthread_create(&th[i], 0, &routine, a) != 0)
            return (1);
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if(pthread_join(th[i], 0) != 0)
            return (2);
        i++;
    }
    sem_destroy(&semaphore);
    return (0);
}
