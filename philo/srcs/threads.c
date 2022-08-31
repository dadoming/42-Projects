#include "../header/philo.h"



// What each philosopher will do
void *routine(void* philosopher)
{
    t_philo *p; 

    p = (t_philo*) philosopher;
    if(p->p_index % 2 == 0)
        usleep(60000);
    while (1)
    {
        if(eat(p) == 0 || _sleep(p) == 0 || think(p) == 0)
            break;
    }
    return (0);
}

int start(t_philo *p, t_table *t)
{
    pthread_t   ph_th[200];

    if(create_threads(ph_th, p, t) != 0)
        return (2);

    if(join_threads(ph_th, t) != 0)
        return (3);
    return (0);
}

// Make threads aka make philosophers
int create_threads(pthread_t *th, t_philo *p, t_table *t)
{
    int i = 0;
    while (i < t->rules.nr_philo)
    {
        if(pthread_create(&th[i], NULL, &routine, (void*)&p[i]) != 0)
        {
            printf("Error creating thread: %d\n", i);
            return (free_mem(t));
        }
        i++;
    }
    return (0);
}

int join_threads(pthread_t *th, t_table *t)
{
    int i = 0;
    while (i < t->rules.nr_philo)
    {
        if(pthread_join(th[i], NULL) != 0)
        {
            printf("Error joining thread: %d\n", i);
            return (free_mem(t));
        }
        i++;
    }
    return (0);
}