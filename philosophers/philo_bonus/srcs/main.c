#include "../includes/philo_bonus.h"

t_table *table(void)
{
    static t_table table;
    return (&table); 
}


t_philo *init_philos(t_philo *p)
{
    int i;

    p = malloc(sizeof(t_philo) * table()->rules.nr_philo);
    i = 0;
    while (i < table()->rules.nr_philo)
    {
        memset(&p[i], 0, sizeof(t_philo));
        p[i].index = i;
        p[i].table = table();
        i++;
    }
    return (p);
}

static int open_sem(char* name, int sem_value)
{
    sem_t *semaphore;

    semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, sem_value);
    sem_unlink(semaphore);
    return (semaphore);
}

int init_semaphores()
{
    table()->forks = open_sem("forks", table()->rules.nr_philo);
    if(table()->forks == SEM_FAILED || 
        ...)
    {
        err_msg("Failed opening semaphores");
        return (-1)
    }
    return (0);
}

int main(int argc, char** argv)
{
    t_philo *p;

    p = NULL;
    if(parse_and_init(argc, argv) != 0)
        return (1); // free_mem
    init_philos(p);
    if(init_semaphores() != 0)
        return (2); //free_mem


    if((table()->forks = sem_open("blaeh", O_CREAT | O_EXCL, 777, 
        table()->rules.nr_philo)) == SEM_FAILED)
    {
        perror("sem_open()");
        return (2);
    }
    if(sem_unlink("blaeh") == -1)
    {
        perror("sem_unlink()");
        return (4);
    }




    if(sem_close(table()->forks) == -1)
    {
        perror("sem_close()");
        return (3);
    }
    
    free(p);
    
    return (0);
}