// Creating threads in a loop

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for(int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);        
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(void)
{
    int i = 0;
    int th_num = 4;
    pthread_t t[4];

    pthread_mutex_init(&mutex, NULL);
    while (i < th_num)
    {
        if(pthread_create(&t[i], NULL, &routine, NULL) != 0)
        {
            printf("Error in iteration %d\n", i);
            return 1;
        }
        printf("Thread %d started\n", i);
        i++;
    }
    i = 0;
    while (i < th_num)
    {
        if(pthread_join(t[i], NULL) != 0)
            return 2;
        printf("Thread %d finished\n", (th_num - 1) - i);
        i++;
    }
    pthread_mutex_destroy(&mutex);

    printf("Mails: %d\n", mails);
    return 0;
}