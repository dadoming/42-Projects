#include "../includes/philo_bonus.h"

table_t *table(void)
{
    static table_t table;
    return (&table); 
}

void *routine(void *arg)
{
    philo_t *p;

    p = (philo_t*)arg;
    if (table()->rules.nr_philo == 1)
    {
        print_status(p, FORK, WHITE);
        action(table()->rules.time_to_die);
        return 0;
    }
    while (1)
    {
        if (eat(p) == 0)
            break;
        if (_sleep(p) == 0)
            break;
        if (think(p) == 0)
            break;
    }
    return (0);
}

void enter_process(philo_t *p)
{
    // pthread_t check;
    
    if(pthread_create(&p->th, NULL, &routine, p) != 0)
    {
        err_msg("Error creating thread");
        return;
    }
    // if(pthread_create(&check, NULL, &death_check, p) != 0)
    // {
        // err_msg("Error creating thread");
        // return;
    // }
    pthread_join(p->th, NULL);
    // pthread_join(check, NULL);
    return;
}

void kill_process(philo_t *p)
{
    int status;
    int i;

    status = 0;
    i = 0;
    while (i++ < table()->rules.nr_philo && status == 0)
	{
	    waitpid(-1, &status, 0);
        status = WEXITSTATUS(status);
    }
    if(status)
    {
        i = 0;
        while (i < table()->rules.nr_philo)
            kill(p[i].pid, SIGKILL);
    }

}

void start_meal(philo_t *p)
{
    int i;

    i = 0;    
    while (i < table()->rules.nr_philo)
    {
        p[i].pid = fork();
        if(p[i].pid == 0)
        {
            enter_process(&p[i]);
        }
        usleep(100);
        i++;
    }
    kill_process(p);
}



int main(int argc, char** argv)
{
    philo_t *p;

    p = NULL;
    if(parse_and_init(argc, argv) != 0)
        return (close_program(p));
    p = init_philos(p);
    if(init_semaphores() != 0)
        return (close_program(p));
    init_shared(p);
    start_meal(p);
    if(table()->ate_all == 1 && table()->died == 0)
        printf("\n%sAll philos ate %d times.\n%s", GREEN, table()->rules.x_eats, RESET);
    close_program(p);
    return (0);
}