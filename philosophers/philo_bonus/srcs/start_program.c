#include "../header/philo_bonus.h"

static void only_one_sitting();
static void routine(t_philo *philo);
static void print_all_eaten();

int noonedied(t_philo *philo)
{
    int i = 0;
    while (i < table()->rules.p_num)
    {
        printf("%d\n", philo[i].is_dead);
        if(philo[i].is_dead == 1)
            return (1);
        i++;
    }
    return (0);
}

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
        //usleep(50);
        i++;
    }

    while (waitpid(-1, &status, WNOHANG <= 0))
    {
        if (WIFEXITED(status) == 1 && WEXITSTATUS(status) == EXIT_SUCCESS)
            break;
    }
    if (noonedied(philo) == 0)
        print_all_eaten();
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
    exit(EXIT_SUCCESS);
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
    printf("\n%s%lld Philo %d died\n%s", RED, \
            table()->time_end, table()->index_death, RESET);
}
