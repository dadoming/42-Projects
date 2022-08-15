// Use of detach

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define THREAD_NUM 2

void *routine()
{
    sleep(1);
    printf("Finished\n");
}

int main(void)
{
    pthread_t t[THREAD_NUM];
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread, PTHREAD_CREATE_DETACHED);
    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        if(pthread_create(&t[i], &detachedThread, routine, NULL) != 0)
            perror("Failed to create thread");
        //pthread_detach(t[i]);
    }
    //for (i = 0; i < THREAD_NUM; i++)
    //{
    //    if(pthread_join(t[i], NULL) != 0)
    //        perror("Failed to join thread");
    //}

    pthread_attr_destroy(&detachedThread);

    pthread_exit(0);
}