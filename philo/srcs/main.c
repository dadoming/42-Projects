#include "../header/philo.h"

void print_last(t_table *t)
{
    if(t->end == 0)
        printf("\n%sAll philos ate %d times.\n%s", GREEN, t->rules.x_eats, RESET);
    else if(t->end != 0)
        printf("\n%s%lld Philo %d died\n%s", RED, t->time_end, t->index_death, RESET);
}

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
    print_last(&t);
    free_mem(&t);
    return (0);
}