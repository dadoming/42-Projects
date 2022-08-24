#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_cond
{
    int nr_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int x_eats;

}   t_cond;

typedef struct s_philo
{
    t_cond *condition;
    pthread_t *philosopher;

}   t_philo;



int ft_atoi(const char *str);
int check_and_load(t_philo *philo, int argc, char **argv);
int check_args(int argc, char **argv);
int check_if_is_number(char **str);
int load_args(t_philo *philo, int argc, char **argv);
void err_msg(char *str);

long get_timestamp();
int join_philos(t_philo *p);
int create_philos(t_philo *p);


void *routine(void *i);

#endif