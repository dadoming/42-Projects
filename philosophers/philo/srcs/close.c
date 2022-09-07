#include "../header/philo.h"

// Free all allocated memory and destroy forks
int free_mem(t_table *t)
{
    int i;

    i = 0;
    if(t->mutex.fork)
    {
        while (i <= t->rules.nr_philo)
        {
            pthread_mutex_destroy(&t->mutex.fork[i]);
            i++;
        }
    }
    pthread_mutex_destroy(&t->mutex.write);
    pthread_mutex_destroy(&t->mutex.dead);
    return (1);
}