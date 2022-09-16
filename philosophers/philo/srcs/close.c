#include "../header/philo.h"

// Free all allocated memory and destroy forks
int free_mem()
{
    int i;

    i = 0;
    if(t()->mutex.fork)
    {
        while (i <= t()->rules.nr_philo)
        {
            pthread_mutex_destroy(&(t()->mutex.fork[i]));
            i++;
        }
    }
    pthread_mutex_destroy(&(t()->mutex.write));
    pthread_mutex_destroy(&(t()->mutex.dead));
    return (1);
}

void print_last()
{
    if(t()->end == 0)
        printf("\n%sAll philos ate %d times.\n%s", GREEN, t()->rules.x_eats, RESET);
    else if(t()->end != 0)
        printf("\n%s%lld Philo %d died\n%s", RED, t()->time_end, t()->index_death, RESET);
}