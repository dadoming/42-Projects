#include "../header/philo_bonus.h"

static void print_dead(t_philo *p, long long time_now);

void philo_death(t_philo *p, long long time_now)
{
    int i = 0;
    sem_wait(table()->sem.print);
    print_dead(p, time_now);
    pthread_detach(p->checker);
    pthread_detach(p->ender);
    sem_post(table()->sem.died);
    p->is_dead = 1;
    while (i++ < table()->rules.p_num)
        sem_post(table()->sem.end);
}

void *check_death(void *arg)
{
    t_philo *p;
    long long time_now;

    p = (t_philo *) arg;
    while (1)
    {
        time_now = get_delta_t();
        if((time_now - p->delta_death) > table()->rules.time_die)
        {
            philo_death(p, time_now);
        }
    }
    return (NULL);
}

static void print_dead(t_philo *p, long long time_now)
{
    printf("\n%s%lld Philo %d died%s\n", RED, \
            time_now, p->index, RESET);
}
