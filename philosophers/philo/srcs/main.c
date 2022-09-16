#include "../header/philo.h"

t_table *t(void)
{
    static t_table table;
    return (&table);
}


int main(int argc, char **argv)
{
    t_philo p[200];

    if(check_and_load(argc, argv) != 0)
        return (1);
    init_mutexes();
    init_philos(p);
    start_timer();
    if(start(p) != 0)
        return(2);
    print_last();
    free_mem();
    return (0);
}