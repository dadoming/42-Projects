#include "../header/philo.h"

void action(long long timer)
{
    usleep(timer * 1000);
}

void pick(t_philo *p)
{
    pthread_mutex_lock(&p->table->mutex.fork[p->hand[LEFT]]);
    print_status(p, FORK, WHITE);
    pthread_mutex_lock(&p->table->mutex.fork[p->hand[RIGHT]]);
    print_status(p, FORK, WHITE);
}

int eat(t_philo *p)
{
    pick(p);
    print_status(p, EAT, GREEN);
    action(p->table->rules.time_to_eat);
    p->x_eaten++;
    pthread_mutex_unlock(&p->table->mutex.fork[p->hand[LEFT]]);
    pthread_mutex_unlock(&p->table->mutex.fork[p->hand[RIGHT]]);
    if(p->x_eaten == p->table->rules.x_eats)
    {
        print_status(p, "ate all his meals", GREEN);
        return 0;
    }
    return (1);
}

int _sleep(t_philo *p)
{
    print_status(p, SLEEP, YELLOW);
    action(p->table->rules.time_to_sleep);
    return (1);
}

int think(t_philo *p)
{
    print_status(p, THINK, BLUE);
    return (1);
}