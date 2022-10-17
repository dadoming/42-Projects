#include "../header/philo.h"

int check_end(t_philo *p)
{
    pthread_mutex_lock(&p->table->mutex.end);
    if(p->table->end != 0)
    {
        pthread_mutex_unlock(&p->table->mutex.end);    
        return(0);
    }
    pthread_mutex_unlock(&p->table->mutex.end);
    return (1);
}

// Print action
int print_status(t_philo *p, char *status, char *color)
{
    long long int current_time;

    if(check_end(p) == 0)
        return (0);
    pthread_mutex_lock(&p->table->mutex.write);
    current_time = get_delta_t();
    printf("%s%lld", color, current_time);
    printf("  %d  %s%s\n", p->p_index, status, RESET);
    if(ft_strcmp(status, EAT) == 0)
        p->delta_death = current_time;
    pthread_mutex_unlock(&p->table->mutex.write);
    return (1);
}