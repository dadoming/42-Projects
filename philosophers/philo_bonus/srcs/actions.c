#include "../header/philo_bonus.h"

static void pick_forks(t_philo *p);
static void drop_forks();

void eat(t_philo *p)
{
    pick_forks(p);
    print_status(p, EAT, GREEN);
    p->delta_death = get_delta_t();
    ft_usleep(table()->rules.time_eat);
    if (table()->rules.max_eat > 0)
        p->times_eaten++;
    drop_forks(p);
}

static void pick_forks(t_philo *p)
{
    sem_wait(table()->sem.forks);
    print_status(p, FORK, WHITE);
    sem_wait(table()->sem.forks);
    print_status(p, FORK, WHITE);
}

static void drop_forks()
{
    sem_post(table()->sem.forks);
    sem_post(table()->sem.forks);
}
