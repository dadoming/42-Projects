#include "../includes/philo_bonus.h"

table_t *table(void)
{
    static table_t table;
    return (&table); 
}

void action(int time)
{
    usleep(time * 1000);
}

void pick_forks(philo_t *p)
{
    sem_wait(table()->semaphore.forks);
    print_status(p, FORK, WHITE);
    sem_wait(table()->semaphore.forks);
    print_status(p, FORK, WHITE);
}

void drop_forks()
{
    sem_post(table()->semaphore.forks);
    sem_post(table()->semaphore.forks);
}

void eat(philo_t *p)
{
    pick_forks(p);
    print_status(p, EAT, GREEN);
    action(table()->rules.time_to_eat);
    if(p->x_eaten > 0)
        p->x_eaten++;
    p->t_left_after_eat = get_delta_t(table()->time_start) + table()->rules.time_to_die;
    drop_forks();
}

void _sleep(philo_t *p)
{
    print_status(p, SLEEP, YELLOW);
    action(table()->rules.time_to_sleep);
}

void think(philo_t *p)
{   
    print_status(p, THINK, BLUE);
}

void enter_process(philo_t *p)
{
    //pthread_t check;

    p->t_left_after_eat = get_timestamp() + table()->rules.time_to_die;
    //pthread_create(check)
    //pthread_detach(check)
    while (1)
    {
        eat(p);
        _sleep(p);
        think(p);
    }
}

void start_meal(philo_t *p)
{
    int i;
    
    i = 0;    
        
    while (i < table()->rules.nr_philo)
    {
        p[i].pid = fork();
        printf("%d && %d\n", getpid(), getppid());
        if(p[i].pid == 0)
        {
            printf("HELLO WORLD\n");
            enter_process(&p[i]);
        }
        i++;
    }
}

int main(int argc, char** argv)
{
    philo_t p[200];

    if(parse_and_init(argc, argv) != 0)
        return (close_program(p));
    init_philos(p);
    printf("%d\n", p[0].index);
    if(init_semaphores() != 0)
        return (close_program(p));
    start_time(p);
    start_meal(p);
    

    close_program(p);
    return (0);
}