#include "../header/philo.h"

static void death_values(t_philo *p, long long int time_now);
static int ate_all(t_philo *p);
static int check_end();

int stop(t_philo *p)
{
    long long time_now;

    if(check_end() == TRUE || ate_all(p))
        return (TRUE);
    time_now = get_delta_t(table()->time_start);
    if((time_now - p->delta_death) > table()->rules.time_die)
    {
        death_values(p, time_now);
        return (TRUE);
    }
    return (FALSE);
}

static void death_values(t_philo *p, long long int time_now)
{
    pthread_mutex_lock(&table()->mutex.dead);
    table()->time_end = time_now;
    table()->index_death = p->index;
    pthread_mutex_unlock(&table()->mutex.dead);
}

static int ate_all(t_philo *p)
{
    if((table()->rules.max_eat > 0) && \
        (p->times_eaten == table()->rules.max_eat))
        return (TRUE);
    return(FALSE);
}

static int check_end()
{
    pthread_mutex_lock(&table()->mutex.dead);
    if(table()->index_death != 0)
    {
        pthread_mutex_unlock(&table()->mutex.dead);
        return(TRUE);
    }
    pthread_mutex_unlock(&table()->mutex.dead);
    return (FALSE);
}
