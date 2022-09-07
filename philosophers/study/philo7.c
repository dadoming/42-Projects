// Use of the trylock function

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *routine(void *arg)
{
    //pthread_mutex_trylock returns an EBUSY value
    if(pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Enterred lock\n");
        // Because the function is paused for a second, the mutex was not unlocked and therefore only one thread got the lock
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else 
    {
        printf("Didn't get lock\n");
    }
}

int main(void)
{
    pthread_t t[4];
    int i = 0;
    pthread_mutex_init(&mutex, NULL);
    while (i < 4)
    {
        if(pthread_create(&t[i], NULL, &routine, NULL) != 0)
            return 1;
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if(pthread_join(t[i], NULL) != 0)
            return 2;
        i++;
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}