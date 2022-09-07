// Introduction to the use of condition variable to send and wait for signals

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *fuel_filling(void *arg)
{
    int i = 0;
    while (i < 5)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled! Amount: %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
        i++;
    }
}

void *car(void *arg)
{
    while (fuel < 40) 
    {
        printf("Waiting for filling...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        // This function cond_wait is equivalent to:
        //   pthread_mutex_unlock(&mutexFuel);
        //   then wait for signal from pthread_cond_signal(&condFuel);
        //   pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Used fuel. Fuel left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(void)
{
    pthread_t t[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    int i = 0;
    while (i < 2)
    {
        if(i == 1)
        {
            if(pthread_create(&t[i], NULL, &fuel_filling, NULL) != 0)
                perror("Failed to create thread");
        }
        else 
        {
            if(pthread_create(&t[i], NULL, &car, NULL) != 0)
                perror("Failed to create thread");
        }
        i++;
    }
    i = 0;
    while (i < 2)
    {
        if(pthread_join(t[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
    pthread_cond_destroy(&condFuel);
    pthread_mutex_destroy(&mutexFuel);
    return 0;
}