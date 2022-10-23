#include "../header/philo_bonus.h"

static int only_one_sitting();
static void start_routine(t_philo *philo);

static void start_routine(t_philo *philo)
{
    while (1)
    {
        // fiquei aqui
        if (eat(philo) != FALSE || _sleep(philo) != FALSE \
            || think(philo) != FALSE)
            break;
    }
    return (0);
}

int start_program(t_philo *philo)
{
    int i;

    if(table()->rules.p_num == 1)
    {
        only_one_philo(philo);
        return (FALSE);
    }
    i = 0;
    while (i < table()->rules.p_num)
    {
        philo[i].pid = fork();
        if(philo[i].pid == 0)
            start_routine(&philo[i]);
        usleep(100);
        i++;
    }
    // kill(?)
}

static int only_one_sitting()
{
    printf("%s0   %d   %s%s\n", WHITE, 1, FORK, RESET);
    usleep(1000 * table()->rules.time_die);
    table()->time_end = get_delta_t();
    table()->index_death = 1;
}
