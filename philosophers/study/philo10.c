// Implementation of trylock mutex

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

// chefs = threads
// stove = shared data(mutex)

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = { 100, 100, 100, 100 };

void *routine(void *args)
{
    for (int i = 0; i < 4; i++)
    {
        if(pthread_mutex_trylock(&stoveMutex[i]) == 0) //if there is any stove available
        {
            int fuelNeeded = (rand() % 20);
            if(stoveFuel[i] - fuelNeeded < 0)
                printf("No more fuel...\n");
            else 
            {
                stoveFuel[i] -= fuelNeeded;
                usleep(500000);
                printf("Fuel left in %d: %d\n", i, stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break;
        }
        else 
        {
            if(i == 3)
            {
                usleep(300000);
                i = 0;
            }
        }
    }
}

int main(void)
{
    srand(time(NULL));
    pthread_t t[10];
    for(int i = 0; i < 4; i++)
        pthread_mutex_init(&stoveMutex[i], NULL);
    int i = 0;
    while (i < 10)
    {
        if(pthread_create(&t[i], NULL, routine, NULL) != 0)
            perror("Error creating thread");
        i++;
    }
    i = 0;
    while (i < 10)
    {
        if(pthread_join(t[i], NULL) != 0)
            perror("Error joining thread");
        i++;
    }
    for(int i = 0; i < 4; i++)
        pthread_mutex_destroy(&stoveMutex[i]);
    return 0;
}