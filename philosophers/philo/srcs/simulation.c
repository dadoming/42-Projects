#include "../header/philo.h"

static void drop_forks(t_philo *p)
{
    pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
    pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
}

static void pick_forks(t_philo *p)
{
    pthread_mutex_lock(&table()->mutex.fork[p->hand[LEFT]]);
    pthread_mutex_lock(&table()->mutex.fork[p->hand[RIGHT]]);
    print_status(p, FORK, WHITE);
    print_status(p, FORK, WHITE);
}

int eat(t_philo *p)
{
    if(stop(p) == TRUE)
        return (TRUE);
    pick_forks(p);
    if (print_status(p, EAT, GREEN) == TRUE)
    {
        drop_forks(p);
        return (TRUE);
    }
    action(table()->rules.time_eat);
    drop_forks(p);
    p->times_eaten++;
    if(table()->rules.max_eat > 0 && \
        p->times_eaten >= table()->rules.max_eat)
        return (TRUE);
    return (FALSE);
}

int think(t_philo *p)
{
    if(stop(p) == TRUE)
        return (TRUE);
    if (print_status(p, THINK, BLUE) == TRUE)
        return (TRUE);
    return (FALSE);
}

int _sleep(t_philo *p)
{
    if(stop(p) == TRUE)
        return (TRUE);
    if (print_status(p, SLEEP, YELLOW) == TRUE)
        return (TRUE);
    action(table()->rules.time_sleep);
    if(stop(p) == TRUE)
        return (TRUE);
    return (FALSE);
}