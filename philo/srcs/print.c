#include "../header/philo.h"

// Print action
int print_status(t_philo *p, char *status, char *color)
{
    long long int current_time;

    if(p->table->end != 0)
        return (0);
    pthread_mutex_lock(&p->table->mutex.write);
    current_time = get_delta_t(p->table->rules.time_start);
    printf("%s%lld", color, current_time);
    printf("  %d  %s%s\n", p->p_index, status, RESET);
    if(ft_strcmp(status, EAT) == 0)
        p->delta_death = current_time;
    pthread_mutex_unlock(&p->table->mutex.write);
    return (1);
}