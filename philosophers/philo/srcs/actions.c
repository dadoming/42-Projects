#include "../header/philo.h"

void action(long long timer)
{
    usleep(timer * 1000);
}

void pick_forks(t_philo *p)
{
    pthread_mutex_lock(&p->table->mutex.fork[p->hand[LEFT]]);
    print_status(p, FORK, WHITE);
    pthread_mutex_lock(&p->table->mutex.fork[p->hand[RIGHT]]);
    print_status(p, FORK, WHITE);
}

int eat(t_philo *p)
{
    pick_forks(p);
    if (!print_status(p, EAT, GREEN))
    {
        pthread_mutex_unlock(&p->table->mutex.fork[p->hand[LEFT]]);
        pthread_mutex_unlock(&p->table->mutex.fork[p->hand[RIGHT]]);
        return (0);
    }
    action(p->table->rules.time_to_eat);
    pthread_mutex_unlock(&p->table->mutex.fork[p->hand[LEFT]]);
    pthread_mutex_unlock(&p->table->mutex.fork[p->hand[RIGHT]]);
    p->x_eaten++;
    if(p->table->rules.x_eats > 0 && p->x_eaten >= p->table->rules.x_eats)
    {
        p->table->how_many_ate++;
        print_status(p, "ate all his meals", GREEN);
        return 0;
    }
    return (1);
}

int _sleep(t_philo *p)
{
    if(!print_status(p, SLEEP, YELLOW))
        return 0;
    action(p->table->rules.time_to_sleep);
    return (1);
}

int think(t_philo *p)
{
    if(!print_status(p, THINK, BLUE))
        return 0;
    return (1);
}