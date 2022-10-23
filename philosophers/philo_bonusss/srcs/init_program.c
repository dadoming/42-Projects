#include "../header/philo_bonus.h"

static int  init_rules(int argc, char **argv);
static void init_philos(t_philo *philo);
static int init_semaphores();
static void open_sem(char* name, int sem_value, sem_t *s);

int init_program(int argc, char **argv, t_philo *philo)
{
    if (init_rules(argc, argv) == TRUE)
    {
        err_msg("Something is wrong with the input values");
        return (TRUE);
    }
    if (init_semaphores() == TRUE)
    {
        destroy_semaphores();
        return (TRUE);
    }
    init_philos(philo);
    return (FALSE);
}

static void open_sem(char* name, int sem_value, sem_t *s)
{
    sem_unlink(name);
    s = sem_open(name, O_CREAT | O_EXCL, 0644, sem_value);
}

static int init_semaphores()
{
    open_sem("forks", table()->rules.p_num, &table()->sem.forks);
    open_sem("died", 1, &table()->sem.died);
    open_sem("print", 1, &table()->sem.print);
    open_sem("stop", 1, &table()->sem.stop);
    if(&table()->sem.forks == SEM_FAILED || \
        &table()->sem.died == SEM_FAILED || \
        &table()->sem.print == SEM_FAILED || \
        &table()->sem.stop == SEM_FAILED)
    {
        err_msg("Failed opening semaphores");
        return (TRUE);
    }
    return (FALSE);
}

static int init_rules(int argc, char **argv)
{
    table()->rules.p_num        =   ft_atoi(argv[1]);
    table()->rules.time_die     =   ft_atoi(argv[2]);
    table()->rules.time_eat     =   ft_atoi(argv[3]);
    table()->rules.time_sleep   =   ft_atoi(argv[4]);
    if (argc == 6)
        table()->rules.max_eat  =   ft_atoi(argv[5]);
    if ((table()->rules.p_num < 1 || table()->rules.p_num > 200) \
        || (table()->rules.time_die     <= 0) \
        || (table()->rules.time_eat     <= 0) \
        || (table()->rules.time_sleep   <= 0) \
        || (table()->rules.max_eat      < 0))
        return (TRUE);
    if (argc == 5)
        table()->rules.max_eat = -1;
    return (FALSE);
}

static void init_philos(t_philo *philo)
{
    int i;
    
    i = 0;
    while(i < table()->rules.p_num)
    {
        memset(&philo[i], 0, sizeof(t_philo));
        philo[i].index = i + 1;
        philo[i].delta_death = table()->rules.time_die;
        philo[i].times_eaten = 0;
        i++;
    }
}
