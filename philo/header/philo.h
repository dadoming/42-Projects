#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct philo_controller
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_philo;

int ft_atoi(const char *str);
int check_and_load(t_philo *philo, int argc, char **argv);
int check_args(int argc, char **argv);
int check_if_is_number(char **str);
int load_args(t_philo *philo, int argc, char **argv);
void err_msg(char *str);

#endif