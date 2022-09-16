#include "../header/philo.h"

void start_timer()
{
    t()->rules.time_start = get_timestamp();
}

long long get_delta_t()
{
    return (get_timestamp() - t()->rules.time_start);
}

long long get_timestamp(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000 + t.tv_usec / 1000); 
}