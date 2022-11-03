#include "../header/philo.h"

static void drop_forks(t_philo *p)
{
    pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
    pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
}

static void pick_forks(t_philo *p)
{
    pthread_mutex_lock(&table()->mutex.fork[p->hand[LEFT]]);
    print_status(p, FORK, WHITE);
    pthread_mutex_lock(&table()->mutex.fork[p->hand[RIGHT]]);
    print_status(p, FORK, WHITE);
}

int eat(t_philo *p)
{
    if(check_end() == TRUE)
        return (TRUE);
    pick_forks(p);
    if(check_end() == TRUE)
        return (TRUE);
    print_status(p, EAT, GREEN);
    ft_usleep(table()->rules.time_eat);
    p->delta_death = get_delta_t();
    if(check_end() == TRUE)
    {
        drop_forks(p);
        return (TRUE);
    }
    p->times_eaten++;
    drop_forks(p);
    if(table()->rules.max_eat > 0 && \
        p->times_eaten >= table()->rules.max_eat)
        return (TRUE);
    return (FALSE);
}

int think(t_philo *p)
{
    if(check_end() == TRUE)
        return (TRUE);
    print_status(p, THINK, MAGENTA);
    return (FALSE);
}

int _sleep(t_philo *p)
{
    if(check_end() == TRUE)
        return (TRUE);
    print_status(p, SLEEP, YELLOW);
    ft_usleep(table()->rules.time_sleep);
    if(check_end() == TRUE)
        return (TRUE);
    return (FALSE);
}