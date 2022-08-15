#include "../header/philo.h"

int main(int argc, char **argv)
{
    t_philo *philo;

    philo = malloc(sizeof(int) * 5);
    // Check input
    if(check_and_load(philo, argc, argv) != 0)
        return (-1);
    
    // Make threads
    pthread_t *philosophers;
    philosophers = malloc(sizeof(pthread_t) * philo->number_of_philosophers);
    forks = philo->number_of_philosophers

    // Print Values
    printf("%d\n", philo->number_of_philosophers);
    printf("%d\n", philo->time_to_die);
    printf("%d\n", philo->time_to_eat);
    printf("%d\n", philo->time_to_sleep);
    printf("%d\n", philo->number_of_times_each_philosopher_must_eat);
    
    
    free(philo);
    return (0);
}