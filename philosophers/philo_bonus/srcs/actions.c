#include "../includes/philo_bonus.h"

int eat(philo_t *p)
{
    if(table()->died == 1)
        return (0);
    sem_wait(table()->semaphore.forks);
    print_status(p, FORK, WHITE);
    sem_wait(table()->semaphore.forks);
    print_status(p, FORK, WHITE);
    print_status(p, EAT, GREEN);
    action(table()->rules.time_to_eat);
    if(p->x_eaten >= 0)
        p->x_eaten += 1;
    p->t_left_after_eat = get_timestamp() + table()->rules.time_to_die;
    if (table()->rules.x_eats > 0 && p->x_eaten >= table()->rules.x_eats)
    {
        table()->ate_all = 1;
        // if died then     ate_all=0
        sem_post(table()->semaphore.forks);
        sem_post(table()->semaphore.forks);
        return (0);
    } 
    sem_post(table()->semaphore.forks);
    sem_post(table()->semaphore.forks);
    if(table()->died == 1)
        return (0);
    return (1);
}

int _sleep(philo_t *p)
{
    if(table()->died == 1)
        return (0);
    print_status(p, SLEEP, YELLOW);
    action(table()->rules.time_to_sleep);
    if(table()->died == 1)
        return (0);
    return (1);
}

int think(philo_t *p)
{
    if(table()->died == 1)
        return (0);
    print_status(p, THINK, BLUE);
    return(1);
}