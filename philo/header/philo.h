#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

// https://gist.github.com/WestleyK/dc71766b3ce28bb31be54b9ab7709082
# define RED        "\033[0;31;7m"
# define GREEN      "\033[0;32;7m"
# define YELLOW     "\033[0;33;7m"
# define BLUE       "\033[0;34;7m"
# define WHITE      "\033[0;37;7m"
# define RESET		"\033[0m"

# define EAT        "is eating"
# define SLEEP      "is sleeping"
# define THINK      "is thinking"
# define DIED       "died"
# define FORK       "has taken a fork"

# define LEFT       0
# define RIGHT      1

typedef struct      s_mutex
{
    pthread_mutex_t fork[200];
    pthread_mutex_t write;

}                   t_mutex;

typedef struct      s_rules
{
    int             nr_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             x_eats;
    long long int   time_start;

}                   t_rules;

typedef struct      s_table
{
    t_rules         rules;
    t_mutex         mutex;
    int             dead;

}                   t_table;

typedef struct      s_philo
{
    int             p_index;
    int             hand[2];
    t_table         *table;
    int             x_eaten;

}                   t_philo;

/*
**  time.c    
*/
long long   get_timestamp();
long long   get_delta_t(long long start_time);
void        start_timer(t_table *t);

/*
**  utils.c
*/
int         ft_atoi(const char *str);
int         check_if_is_number(char **str);
void        err_msg(char *str);

/*
**  close_t.c
*/
int         free_mem(t_table *t);

/*
**  parser.c
*/
int         check_and_load(t_table *t, int argc, char **argv);
int         load_args(t_table *table, int argc, char **argv);

/*
**  main.c
*/
void        init_mutexes(t_mutex *mutex, int nr_philo);
void        init_philos(t_philo *p, t_table *t);

/*
**  threads.c
*/
void        *routine(void *philo_struct);
int         start(t_philo *p, t_table *t);
int         create_threads(pthread_t *th, t_philo *p, t_table *t);
int         join_threads(pthread_t *th, t_table *t);

/*
**  print.c
*/
void        print_status(t_philo *p, char *status, char *color);

/*
**  actions.c
*/
int eat(t_philo *p);
int _sleep(t_philo *p);
int think(t_philo *p);
void pick(t_philo *p);
void action(long long timer);

#endif