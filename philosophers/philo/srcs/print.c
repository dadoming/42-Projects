#include "../header/philo.h"

void print_end()
{
    if(table()->index_death == 0)
        printf("\n%sAll philos ate %d times.\n%s", BOLDGREEN, \
            table()->rules.max_eat, RESET);
    else if(table()->index_death != 0)
        printf("\n%s%lld\t%d\tdied\n%s", BOLDRED, \
            table()->time_end, table()->index_death, RESET);
}

void print_status(t_philo *p, char *status, char *color)
{
    long long current_time;

    if(check_end() == TRUE)
        return;
    pthread_mutex_lock(&table()->mutex.write);
    current_time = get_delta_t();
    printf("%s%lld\t%d\t%s%s\n", color, current_time, \
            p->index, status, RESET);
    pthread_mutex_unlock(&table()->mutex.write);
}
