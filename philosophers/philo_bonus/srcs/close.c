#include "../includes/philo_bonus.h"

static int close_semaphores()
{
    if (table()->semaphore.forks)
    {
        if(sem_close(table()->semaphore.forks) == -1)
            return (-1);
        if(sem_close(table()->semaphore.died) == -1)
            return (-1);
        if(sem_close(table()->semaphore.print) == -1)
            return (-1);
    }
    return (0);
}

int close_program(philo_t *p)
{
    if(close_semaphores() == -1)
    {
        printf("Error closing semaphores\n");
        return(-1);
    }    
    if(p)
        free(p);
    return(0);
}