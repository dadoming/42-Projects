#include "../includes/philo_bonus.h"

sem_t *open_sem(char* name, int sem_value)
{
    sem_t *semaphore;

    sem_unlink(name);
    semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, sem_value);
    sem_unlink(name);
    return (semaphore);
}

int init_semaphores()
{
    table()->semaphore.forks = open_sem("forks", table()->rules.nr_philo);
    table()->semaphore.died = open_sem("died", 1);
    table()->semaphore.print = open_sem("print", 1);
    table()->semaphore.stop = open_sem("stop", 1);
    if(table()->semaphore.forks == SEM_FAILED || \
        table()->semaphore.died == SEM_FAILED || \
        table()->semaphore.print == SEM_FAILED || \
        table()->semaphore.stop == SEM_FAILED)
    {
        perror("SEM_OPEN");
        err_msg("Failed opening semaphores");
        return (-1);
    }
    return (0);
}