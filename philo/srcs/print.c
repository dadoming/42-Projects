#include "../header/philo.h"

// Print action
void print_status(t_philo *p, char *status, char *color)
{
    long long int current_time;

    pthread_mutex_lock(&p->table->mutex.write);
    current_time = get_delta_t(p->table->rules.time_start);
    printf("%s%lld", color, current_time);
    printf("  %d  %s%s\n", p->p_index + 1, status, RESET);
    pthread_mutex_unlock(&p->table->mutex.write);
}