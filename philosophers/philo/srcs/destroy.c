#include "../header/philo.h"

void destroy_program()
{
    int i;

    i = 0;
    if(table()->mutex.fork)
    {
        while (i < table()->rules.p_num)
        {
            pthread_mutex_destroy(&(table()->mutex.fork[i]));
            i++;
        }
    }
    pthread_mutex_destroy(&(table()->mutex.write));
    pthread_mutex_destroy(&(table()->mutex.dead));
}
