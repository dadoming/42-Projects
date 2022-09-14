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

    if(table()->semaphore.forks == SEM_FAILED || \
        table()->semaphore.died == SEM_FAILED || \
        table()->semaphore.print == SEM_FAILED 
        )
    {
        perror("SEM_OPEN ");
        err_msg("Failed opening semaphores");
        return (-1);
    }
    return (0);
}

philo_t *init_philos(philo_t *p)
{
    int i;

    p = malloc(sizeof(philo_t) * table()->rules.nr_philo);
    if(!p)
        return (NULL);
    i = 0;
    while (i < table()->rules.nr_philo)
    {
        memset(&p[i], 0, sizeof(philo_t));
        p[i].index = i;
        p[i].table = table();
        i++;
    }
    return (p);
}

int load_args(int argc, char **argv)
{
    table()->rules.nr_philo = ft_atoi(argv[1]);
    table()->rules.time_to_die = ft_atoi(argv[2]);
    table()->rules.time_to_eat = ft_atoi(argv[3]);
    table()->rules.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        table()->rules.x_eats = ft_atoi(argv[5]);
    if (table()->rules.nr_philo < 1 || table()->rules.nr_philo > 200 
            || table()->rules.time_to_die <= 0   || table()->rules.time_to_eat <= 0 
            || table()->rules.time_to_sleep <= 0 || table()->rules.x_eats < 0)
        return (1);
    // ?
    if(argc == 5)
        table()->rules.x_eats = -1;
    return 0;
}

int parse_and_init(int argc, char** argv)
{
    if(argc < 5 || argc > 6)
    {
        err_msg("Wrong number of arguments");
        return (1);
    }
    if(check_if_is_number(argv) != 0)
    {
        err_msg("Wrong input");
        return (2);
    }
    if(load_args(argc, argv) != 0)
    {
        err_msg("Error in your numbers");
        return (3);
    }
    return (0);
}