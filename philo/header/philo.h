#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct philo_controller
{
    // Number of philosophers and also number of forks
    int number_of_philosophers;
    
    /* Is in miliseconds, and if a philosopher does not start
    eating time_to_die miliseconds after starting his last meal
    or the beggining of the simulation, it dies. */
    int time_to_die;

    /* Is in miliseconds and is the time it takes for a
    philosopher to eat. During this time he must keep the
    2 forks */
    int time_to_eat;

    /* Is in miliseconds and is the time the philosopher
    will spend sleeping. */
    int time_to_sleep;

    /*(Optional) If all philosophers eat this amount of times
    the simulation will stop. If not specified it will only 
    stop at a death of a philosopher. */
    int number_of_times_each_philosopher_must_eat;

} t_philo;



int ft_atoi(const char *str);
int check_and_load(t_philo *philo, int argc, char **argv);
int check_args(int argc, char **argv);
int check_if_is_number(char **str);
int load_args(t_philo *philo, int argc, char **argv);
void err_msg(char *str);

void *routine();

#endif