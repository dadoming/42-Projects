#include "../header/philo_bonus.h"

static void only_one_sitting();
static void routine(t_philo *philo);

static void print_all_eaten();


void start_program(t_philo *philo)
{
    int i;
    int status;

    if(table()->rules.p_num == 1)
    {
        only_one_sitting(philo);
        return;
    }
    i = 0;
    while (i < table()->rules.p_num)
    {
        philo[i].pid = fork();
        if(philo[i].pid == 0)
            routine(&philo[i]);
        usleep(50);
        i++;
    }

    while (waitpid(-1, &status, WNOHANG) <= 0)
    {
        if(WEXITSTATUS(status) == 1)
        {
            kill_all(philo);
            return;
        }
    }
    
    kill_all(philo);
    print_all_eaten();
}

static void routine(t_philo *philo)
{
    pthread_t checker;

    pthread_create(&checker, NULL, check_death, &philo);
    while (1)
    {
        if (eat(philo) != FALSE)
        {
            pthread_detach(checker);
            exit(0);
        }
        print_status(philo, SLEEP, YELLOW);
        action(table()->rules.time_sleep);
        print_status(philo, THINK, BLUE);
    }
    pthread_detach(checker);
}



static void print_all_eaten()
{
    printf("\n%sAll philos ate %d times.\n%s", GREEN, \
            table()->rules.max_eat, RESET);
}

static void only_one_sitting()
{
    printf("%s0   %d   %s%s\n", WHITE, 1, FORK, RESET);
    usleep(1000 * table()->rules.time_die);
    table()->time_end = get_delta_t();
    table()->index_death = 1;
}
