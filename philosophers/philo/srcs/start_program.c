#include "../header/philo.h"

static int      only_one_sitting();
static int      create_threads(pthread_t *th, t_philo *p);
static int      join_threads(pthread_t *th);
static void*    routine(void* philo);

int start_program(t_philo *philo)
{
    pthread_t th[200];

    if (only_one_sitting() == TRUE)
        return (FALSE);
    if (create_threads(th, philo) == TRUE)
        return (TRUE);
    if (join_threads(th) == TRUE)
        return (TRUE);
    return (FALSE);
}

static void* routine(void* philo)
{
    t_philo *p;

    p = (t_philo*) philo;
    if (p->index % 2 == 0)
        ft_usleep(100);
    pthread_create(&p->checker, NULL, stop, p);
    pthread_detach(p->checker);
    while (1)
    {
        if (eat(p) != FALSE || _sleep(p) != FALSE || think(p) != FALSE)
            break;
    }
    return (0);
}

static int create_threads(pthread_t *th, t_philo *p)
{
    int i;
    
    i = 0;
    while (i < table()->rules.p_num)
    {
        if(pthread_create(&th[i], NULL, routine, &p[i]) != 0)
        {
            err_msg("Error creating thread");
            destroy_program();
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

static int join_threads(pthread_t *th)
{
    int i;

    i = 0;
    while (i < table()->rules.p_num)
    {
        if(pthread_join(th[i], NULL) != 0)
        {
            err_msg("Error joining thread");
            destroy_program();
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

static int only_one_sitting()
{
    if(table()->rules.p_num == 1)
    {
        printf("%s%lld\t%d\t%s%s\n", WHITE, get_delta_t(), 1, FORK, RESET);
        ft_usleep(table()->rules.time_die);
        table()->time_end = get_delta_t();
        table()->index_death = 1;
        return (TRUE);
    }
    return (FALSE);
}
