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
            sem_wait(table()->sem.print);
            return (0);
        }
        if (p->times_eaten >= table()->rules.max_eat && \
            table()->rules.max_eat > 0)
            break;
    }
    return (NULL);
}

static int dead(t_philo *p)
{
    long long time_now;

    time_now = get_delta_t(table()->time_start);
    if((time_now - p->delta_death) > table()->rules.time_die)
    {
        death_values(p, time_now);
        print_dead(p);
        p->is_dead = 1;
        return (TRUE);
    }
    return(FALSE);
}

static void death_values(t_philo *p, long long int time_now)
{
    table()->time_end = time_now;
    table()->index_death = p->index;
}

static void print_dead()
{
    printf("\n%s%lld Philo %d died\n%s", RED, \
            table()->time_end, table()->index_death, RESET);
}
