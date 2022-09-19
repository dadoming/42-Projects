#include "../includes/philo_bonus.h"

long long get_delta_t(long long start_time)
{
    return (get_timestamp() - start_time);
}

long long get_timestamp(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000 + t.tv_usec / 1000); 
}