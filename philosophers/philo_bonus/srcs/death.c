#include "../header/philo_bonus.h"

static void death_values(t_philo *p, long long int time_now);
static int dead(t_philo *p);
static void print_dead();

void *check_death(void *arg)
{
    t_philo *p;

    p = (t_philo *) arg;
    while (1)
    {
        if (dead(p) == TRUE)
        {
            print_dead(p);
            exit(2);
        }
        if (p->times_eaten >= table()->rules.max_eat)
            break;
    }
    return (NULL);
}

static void print_dead()
{
    printf("\n%s%lld Philo %d died\n%s", RED, \
            table()->time_end, table()->index_death, RESET);
}

static int dead(t_philo *p)
{
    long long time_now;

    time_now = get_delta_t(table()->time_start);
    if((time_now - p->delta_death) > table()->rules.time_die)
    {
        sem_wait(table()->sem.died);
        death_values(p, time_now);
        return (TRUE);
    }
    return(FALSE);
}

static void death_values(t_philo *p, long long int time_now)
{
    table()->time_end = time_now;
    table()->index_death = p->index;
}