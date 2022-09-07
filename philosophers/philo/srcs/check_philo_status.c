#include "../header/philo.h"

int death_signal(t_philo *p, long long int time_now)
{
    pthread_mutex_lock(&p->table->mutex.dead);
    p->table->end = p->p_index;
    p->table->time_end = time_now;
    p->table->index_death = p->p_index;
    pthread_mutex_unlock(&p->table->mutex.dead);
    return (1);
}

int ate_all(t_philo *p)
{
    if(p->table->rules.x_eats > 0)
    {
        if(p->x_eaten >= p->table->rules.x_eats)
        {
            return (1);
        }
    }
    return(0);
}

int philo_died(t_philo *p)
{
    long long int time_now;

    if(p->table->end != 0 || ate_all(p))
        return 1;
    time_now = get_delta_t(p->table->rules.time_start);
    if((time_now - p->delta_death) > p->table->rules.time_to_die)
        return (death_signal(p, time_now));
    return 0;
}

void *check_(void *arg)
{
    t_philo *p;

    p = (t_philo*) arg;
    while(1)
    {
        if(philo_died(p) != 0)
            break;
    }
    return 0;
}

