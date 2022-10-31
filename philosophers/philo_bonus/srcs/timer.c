#include "../header/philo_bonus.h"

void start_timer(t_philo *p)
{
    p->time_start = get_timestamp();
}

long long get_delta_t(t_philo *p)
{
    return (get_timestamp() - p->time_start);
}

long long get_timestamp(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000 + t.tv_usec / 1000); 
}

void action(long long timer)
{
    usleep(timer * 1000);
}
