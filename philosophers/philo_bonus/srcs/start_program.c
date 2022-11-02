#include "../header/philo_bonus.h"

static int only_one_sitting();
static void routine(t_philo *philo);

void	*free_all(void *arg)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)arg;
	sem_wait(table()->sem.died);
	i = -1;
	while (++i < table()->rules.p_num)
		kill(p[i].pid, 9);
	destroy(p);
	exit(0);
}

void start_program(t_philo *philo)
{
    int i;
    pthread_t free;

    if(only_one_sitting(philo) == TRUE)
        return;
    i = 0;
    while (i < table()->rules.p_num)
    {
        philo[i].pid = fork();
        if(philo[i].pid == 0)
            routine(&philo[i]);
        i++;
    }
    pthread_create(&free, NULL, free_all, philo);
    i = 0; 
    while (i < table()->rules.p_num)
    {
        waitpid(philo[i].pid, NULL, 0);
        i++;
    }
}

void *enddd(void *arg)
{
    (void) arg;
    sem_wait(table()->sem.end);
    exit(0);
}

static void routine(t_philo *philo)
{
    if(philo->index % 2 == 0)
        usleep(50);
    pthread_create(&philo->checker, NULL, check_death, philo);
    pthread_create(&philo->ender, NULL, enddd, 0);
    int i = 0;
    while ((i < table()->rules.max_eat) || table()->rules.max_eat == -1)
    {
        eat(philo);
        i++;
        if (i == table()->rules.max_eat)
        {
            pthread_detach(philo->checker);
            pthread_detach(philo->ender);
            exit(0);
        }
        print_status(philo, SLEEP, YELLOW);
        ft_usleep(table()->rules.time_sleep);
        print_status(philo, THINK, BLUE);
    }
}

static int only_one_sitting()
{
    if(table()->rules.p_num == 1)
    {
        start_timer();
        printf("%s0   %d   %s%s\n", WHITE, 1, FORK, RESET);
        ft_usleep(table()->rules.time_die);
        table()->time_end = get_delta_t();
        printf("%s%lld Philo 1 died%s\n", RED, \
                table()->time_end, RESET);
        return (TRUE);
    }
    return (FALSE);
}
