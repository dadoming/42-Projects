#include "../header/philo_bonus.h"

static void kill_all(t_philo *p);

int destroy(t_philo *philo)
{
    int i;

    i = 0;
    if (philo[0].pid)
        kill_all(philo);
    if (sem_close(table()->sem.forks) == -1)
        return (TRUE);
    if (sem_close(table()->sem.died) == -1)
        return (TRUE);
    if (sem_close(table()->sem.print) == -1)
        return (TRUE);
    if (philo[0].mutex)
    {
        while (i < table()->rules.p_num)
        {
            if(sem_close(philo[i].mutex) == -1)
                return (TRUE);
            i++;
        }
    }
    return (FALSE);
}

static void kill_all(t_philo *p)
{
    int i;

    i = table()->rules.p_num;
    while (i)
    {
        kill(p[i - 1].pid, SIGKILL);
        i--;
    }
}
