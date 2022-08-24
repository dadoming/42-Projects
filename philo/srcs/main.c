#include "../header/philo.h"

// What each philosopher will do
void *routine(void* philo_struct)
{
    t_philo *p; 
    int ph_nr;

    p = (t_philo*) philo_struct;
    usleep(100000);
    ph_nr = p->p_index++;
    pthread_mutex_unlock(&p->assign);
    printf("I am philosopher %d\n", ph_nr + 1);
    /*
    while (alive(p) == 0)
    {
        pthread_mutex_lock()
    }
    */
    return (0);
}

// Make threads aka make philosophers
int create_philos(t_philo *p)
{
    int i = 0;
    p -> philosopher = malloc(sizeof(pthread_t) * p->rules->nr_philo);
    p -> p_index = 0;
    while (i < p -> rules->nr_philo)
    {
        pthread_mutex_lock(&p->assign);
        if(pthread_create(&p->philosopher[i], NULL, &routine, (void*)p) != 0)
        {
            printf("Error creating thread: %d\n", i);
            return (free_mem(p));
        }
        i++;
    }
    return (0);
}

// Init mutexes
void init_mutexes(t_philo *p)
{
    int i;
    
    i = 0;
    p->fork = malloc(sizeof(pthread_mutex_t) * p->rules->nr_philo);
    while(i < p->rules->nr_philo)
    {
        pthread_mutex_init(&p->fork[i], NULL);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_philo *p;

    p = malloc(sizeof(t_philo));
    if(check_and_load(p, argc, argv) != 0)
        return (1);

    init_mutexes(p);

    pthread_mutex_init(&p->assign, NULL);
    if(create_philos(p) != 0)
        return (2);

    if(join_philos(p) != 0)
        return (3);

    free_mem(p);
    return (0);
}