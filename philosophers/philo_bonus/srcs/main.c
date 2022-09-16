#include "../includes/philo_bonus.h"

table_t *table(void)
{
    static table_t table;
    return (&table); 
}

/*
void *death_check(void *philo)
{
    philo_t *p; 

    p = (philo_t*) philo;
    while (1)
    {
        sem_wait(p->table->semaphore.died);
        if(p->t_left_after_eat < get_timestamp())
        {
            print_status(p, DIED, RED);
            sem_post(table()->semaphore.stop);
        }
        sem_post(p->table->semaphore.died);
        sem_wait(p->table->semaphore.died);
        if((p->table->rules.x_eats >= 0) && (p->table->rules.x_eats <= p->x_eaten))
        {
            printf("\n%sAll philos ate %d times.\n%s", GREEN, table()->rules.x_eats, RESET);
            sem_post(table()->semaphore.stop);
        }
        sem_post(p->table->semaphore.died);
    }
    return (0);
}
*/

void enter_process(philo_t *p)
{
    pthread_t check;

    p->t_left_after_eat = get_timestamp() + table()->rules.time_to_die;
    //pthread_create(&check, NULL, death_check, p);
    //pthread_detach(check);
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

    sem_wait(table()->semaphore.stop);
    i = 0;    
    while (i < table()->rules.nr_philo)
    {
        p[i].pid = fork();
        if(p[i].pid == 0)
        {
            enter_process(&p[i]);
            exit(0);
        }
        i++;
        usleep(100);
    }
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
    start_time(p);
    start_meal(p);
        sem_wait(table()->semaphore.stop);
    close_program(p);
    return (0);
}