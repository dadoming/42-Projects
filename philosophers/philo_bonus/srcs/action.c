#include "../includes/philo_bonus.h"

void pick_forks(philo_t *p)
{
    sem_wait(table()->semaphore.forks);
    print_status(p, FORK, WHITE);
    sem_wait(table()->semaphore.forks);
    print_status(p, FORK, WHITE);
}

void drop_forks()
{
    sem_post(table()->semaphore.forks);
    sem_post(table()->semaphore.forks);
}

void eat(philo_t *p)
{
    pick_forks(p);
    print_status(p, EAT, GREEN);
    action(table()->rules.time_to_eat);
    if(p->x_eaten >= 0)
        p->x_eaten++;
    p->t_left_after_eat = get_delta_t(table()->time_start) + table()->rules.time_to_die;
    drop_forks();
}

void _sleep(philo_t *p)
{
    print_status(p, SLEEP, YELLOW);
    action(table()->rules.time_to_sleep);
}

void think(philo_t *p)
{   
    print_status(p, THINK, BLUE);
}