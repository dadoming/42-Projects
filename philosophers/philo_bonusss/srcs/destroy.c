#include "../header/philo_bonus.h"

int close_semaphores()
{
    if(sem_close(&table()->sem.forks) == -1)
        return (TRUE);
    if(sem_close(&table()->sem.died) == -1)
        return (TRUE);
    if(sem_close(&table()->sem.print) == -1)
        return (TRUE);
    if(sem_close(&table()->sem.stop) == -1)
        return (TRUE);
    return (FALSE);
}