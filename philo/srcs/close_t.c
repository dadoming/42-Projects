#include "../header/philo.h"

// Join threads
int join_philos(t_philo *p)
{
    int i = 0;
    while (i < p -> rules->nr_philo)
    {
        if(pthread_join(p->philosopher[i], NULL) != 0)
        {
            printf("Error joining thread: %d\n", i);
            return (free_mem(p));
        }
        i++;
    }
    return (0);
}

// Free all allocated memory and destroy forks
int free_mem(t_philo *p)
{
    int i = 0;

    if(p->fork)
    {
        while (i < p->rules->nr_philo)
        {
            pthread_mutex_destroy(&p->fork[i]);
            i++;
        }
        free(p->fork);
    }
    pthread_mutex_destroy(&p->assign);
    
    if(p->philosopher)
        free(p->philosopher);
    if(p->rules)
        free(p->rules);
    if(p)
        free(p);
    return (1);
}