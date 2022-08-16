#include "../header/philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int ph = 0;

void *routine()
{
    pthread_mutex_lock(&mutex);
    struct timeval current_time;
    sleep(1);
    gettimeofday(&current_time, NULL);
    printf("usec: %ld ---- I am a philosopher %d\n", current_time.tv_usec / 1000, ++ph);
    pthread_mutex_unlock(&mutex);
    return (0);
}

int main(int argc, char **argv)
{
    t_philo *philo;

    philo = malloc(sizeof(int) * 5);
    // Check input
    if(check_and_load(philo, argc, argv) != 0)
        return (-1);
    
    // Make threads aka make philosophers
    pthread_t *philosophers;
    philosophers = malloc(sizeof(pthread_t) * philo->number_of_philosophers);
    int i = 0;
    while (i < philo -> number_of_philosophers)
    {
        pthread_create(&philosophers[i], NULL, &routine, NULL);
        i++;
    }

    i = 0;
    while (i < philo -> number_of_philosophers)
    {
        pthread_join(philosophers[i], NULL);
        i++;
    }
    

    // Print Values
    printf("%d\n", philo->number_of_philosophers);
    printf("%d\n", philo->time_to_die);
    printf("%d\n", philo->time_to_eat);
    printf("%d\n", philo->time_to_sleep);
    printf("%d\n", philo->number_of_times_each_philosopher_must_eat);
    
    pthread_mutex_destroy(&mutex);

    free(philosophers);
    free(philo);
    return (0);
}