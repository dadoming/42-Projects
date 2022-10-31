#include "../header/philo_bonus.h"

static int only_one_sitting();
static void routine(t_philo *philo);

void start_program(t_philo *philo)
{
    int i;
    int status;

    if(only_one_sitting(philo) == TRUE)
        return;
    i = 0;
    while (i < table()->rules.p_num)
    {
        philo[i].pid = fork();
        if(philo[i].pid == 0)
            routine(&philo[i]);
        usleep(50);
        i++;
    }

    while (WIFEXITED(status) != 1 || WEXITSTATUS(status) != EXIT_SUCCESS)
    {
        waitpid(-1, &status, WNOHANG <= 0);
    }

    kill_all(philo);
}

static void routine(t_philo *philo)
{
    pthread_t checker;

    pthread_create(&checker, NULL, check_death, philo);
    pthread_detach(checker);
    while (1)
    {
        if (eat(philo) != FALSE)
            break;
        if(philo->is_dead == 1)
            break;
        print_status(philo, SLEEP, YELLOW);
        if(philo->is_dead == 1)
            break;
        action(table()->rules.time_sleep);
        if(philo->is_dead == 1)
            break;
        print_status(philo, THINK, BLUE);
    }
    kill(checker, SIGKILL);
    exit(EXIT_SUCCESS);
}

static int only_one_sitting()
{
    if(table()->rules.p_num == 1)
    {
        printf("%s0   %d   %s%s\n", WHITE, 1, FORK, RESET);
        usleep(1000 * table()->rules.time_die);
        table()->time_end = get_delta_t();
        table()->index_death = 1;
        printf("\n%s%lld Philo %d died\n%s", RED, \
                table()->time_end, table()->index_death, RESET);
        return (TRUE);
    }
    return (FALSE);
}
