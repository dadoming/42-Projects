#include "../header/philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int ph = 0;

void *routine(void* philo_rules)
{
    pthread_mutex_lock(&mutex);
    t_cond *p; 
    p = (t_cond*) philo_rules;
    printf("## %d\n", p->time_to_eat);
    pthread_mutex_unlock(&mutex);
    return (0);
}

// Make threads aka make philosophers
int create_philos(t_philo *p)
{
    p -> philosopher = malloc(sizeof(pthread_t) * p->condition->nr_philo);
    int i = 0;
    while (i < p -> condition->nr_philo)
    {
        if(pthread_create(&p->philosopher[i], NULL, &routine, (void*)p->condition) != 0)
        {
            printf("Error creating thread: %d\n", i);
            return (1);
        }
        i++;
    }
    return (0);
}

// Join threads
int join_philos(t_philo *p)
{
    int i = 0;
    while (i < p -> condition->nr_philo)
    {
        if(pthread_join(p->philosopher[i], NULL) != 0)
        {
            printf("Error joining thread: %d\n", i);
            return (1);
        }
        i++;
    }
    free( p -> philosopher);
    return (0);
}



int main(int argc, char **argv)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));
    if(check_and_load(philo, argc, argv) != 0)
        return (1);

    if(create_philos(philo) != 0)
        return (2);

    if(join_philos(philo) != 0)
        return (3);
    

    // Print Values
    printf("%d\n", philo->condition->nr_philo);
    printf("%d\n", philo->condition->time_to_die);
    printf("%d\n", philo->condition->time_to_eat);
    printf("%d\n", philo->condition->time_to_sleep);
    printf("%d\n", philo->condition->x_eats);
    

    pthread_mutex_destroy(&mutex);
    free(philo->condition);
    free(philo);
    return (0);
}