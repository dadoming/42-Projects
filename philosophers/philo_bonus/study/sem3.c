#include "sem.h"

#define THREAD_NUM 7

sem_t sem;

void *routine(void* arg)
{
    sem_wait(&sem);
    sleep(1);
    printf("Hello! [%d]\n", *(int*)arg);
    sem_post(&sem);
    sem_post(&sem);
}

int main(void)
{
    pthread_t th[THREAD_NUM];
    sem_init(&sem, 0, 1);
    int i = 0;
    while (i < THREAD_NUM)
    {
        int* a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], 0, &routine, a) != 0)
            return (2);
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if(pthread_join(th[i], 0) != 0)
            return (2);
        i++;
    }
    sem_destroy(&sem);
    return (0);
}