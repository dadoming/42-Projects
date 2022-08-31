#include "../header/philo.h"

int main(int argc, char **argv)
{
    t_table t;
    t_philo p[200];

    if(check_and_load(&t, argc, argv) != 0)
        return (1);
    init_mutexes(&t.mutex, t.rules.nr_philo);
    init_philos(p, &t);
    start_timer(&t);
    if(start(p, &t) != 0)
        return(2);
    free_mem(&t);
    return (0);
}