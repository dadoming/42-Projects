#include "../header/philo_bonus.h"

void kill_all(t_philo *p)
{
    int i;

    i = table()->rules.p_num;
    while (i)
    {
        kill(p[i - 1].pid, SIGINT);
        i--;
    }
}

int close_semaphores()
{
    if(sem_close(table()->sem.forks) == -1)
        return (TRUE);
    if(sem_close(table()->sem.died) == -1)
        return (TRUE);
    if(sem_close(table()->sem.print) == -1)
        return (TRUE);
    return (FALSE);
}