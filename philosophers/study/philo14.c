// Different ways to initialize thread variables

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define THREAD_NUM 2

// NEW AND FASTER WAY TO INITIALIZE VARIABLES
pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condFuel = PTHREAD_COND_INITIALIZER;

void *routine()
{

}

int main(void)
{
    pthread_t t[6];
    // pthread_mutex_init(&mutexFuel, NULL); No need for this line
    int i = 0;
    while (i < THREAD_NUM)
    {
        if(i == 4 || i == 5)
        {
            if(pthread_create(&t[i], NULL, &routine, NULL) != 0)
                perror("Failed to create thread");
        } 
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if(pthread_join(t[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
    pthread_mutex_destroy(&mutexFuel);
    return 0;
}