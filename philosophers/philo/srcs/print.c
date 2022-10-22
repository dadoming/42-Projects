#include "../header/philo.h"

void print_end()
{
    if(table()->index_death == 0)
        printf("\n%sAll philos ate %d times.\n%s", GREEN, \
            table()->rules.max_eat, RESET);
    else if(table()->index_death != 0)
        printf("\n%s%lld Philo %d died\n%s", RED, \
            table()->time_end, table()->index_death, RESET);
}

int print_status(t_philo *p, char *status, char *color)
{
    long long current_time;

    pthread_mutex_lock(&table()->mutex.write);
    current_time = get_delta_t();
    printf("%s%lld", color, current_time);
    printf("  %d  %s%s\n", p->index, status, RESET);
    if(ft_strcmp(status, EAT) == 0)
        p->delta_death = current_time;
    pthread_mutex_unlock(&table()->mutex.write);
    return (FALSE);
}
