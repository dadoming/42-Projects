#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

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
    pthread_mutex_t fork[202];
    pthread_mutex_t write;
    pthread_mutex_t dead;
    pthread_mutex_t end;

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
    int             end;
    int             index_death;
    int             how_many_ate;
    long long int   time_end;

}                   t_table;

typedef struct      s_philo
{
    int             p_index;
    int             hand[2];
    t_table         *table;
    int             x_eaten;
    long long       delta_death;

}                   t_philo;

t_table *t(void);

/*
**  time.c    
*/
long long   get_timestamp();
long long   get_delta_t();
void        start_timer();

/*
**  utils.c
*/
int         ft_atoi(const char *str);
int         check_if_is_number(char **str);
void        err_msg(char *str);
int         ft_strcmp(char *s1, char *s2);

/*
**  close_t.c
*/
int         free_mem();
void        print_last();

/*
**  parser.c
*/
int         check_and_load(int argc, char **argv);
int         load_args(int argc, char **argv);

/*
**  main.c
*/
void        init_mutexes();
void        init_philos(t_philo *p);

/*
**  threads.c
*/
void        *routine(void *philo_struct);
int         start(t_philo *p);
int         create_threads(pthread_t *th, t_philo *p);
int         join_threads(pthread_t *th);

/*
**  print.c
*/
int         print_status(t_philo *p, char *status, char *color);
int         check_end(t_philo *p);

/*
**  actions.c
*/
int         eat(t_philo *p);
int         _sleep(t_philo *p);
int         think(t_philo *p);
void        pick_forks(t_philo *p);
void        action(long long timer);

/*
**  check_philo_status.c
*/
void        *check_(void *arg);
int         philo_died(t_philo *p);
int         death_signal(t_philo *p, long long int time_now);
int         ate_all(t_philo *p);

#endif