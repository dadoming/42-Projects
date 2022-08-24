#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct      s_rules
{
    int             nr_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             x_eats;

}                   t_rules;

typedef struct      s_philo
{
    t_rules         *rules;
    pthread_t       *philosopher;
    pthread_mutex_t *fork ;
    pthread_mutex_t assign ;
    int p_index;

}                   t_philo;

int     ft_atoi(const char *str);
int     check_and_load(t_philo *philo, int argc, char **argv);
int     check_if_is_number(char **str);
int     load_args(t_philo *philo, int argc, char **argv);
void    err_msg(char *str);

long    get_timestamp();
int     join_philos(t_philo *p);
int     create_philos(t_philo *p);
int     free_mem(t_philo *p);
void    init_mutexes(t_philo *p);

void    *routine(void *philo_struct);

#endif