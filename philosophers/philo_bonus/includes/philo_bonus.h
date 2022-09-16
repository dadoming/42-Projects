#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


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


typedef struct rules_s
{
    int             nr_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             x_eats;

}   rules_t;

typedef struct semaph_s
{
    sem_t           *forks;
    sem_t           *died;
    sem_t           *print;
    sem_t           *stop;

}   semaph_t;

typedef struct table_s
{
    long long int   time_start;
    rules_t         rules;
    semaph_t        semaphore;

}   table_t;

typedef struct philo_s
{
    int             index;
    int             x_eaten;
    int             t_left_after_eat;
    pid_t           pid;
    table_t         *table;

}   philo_t;


/*
**  main.c
*/
table_t     *table(void);

int         check_if_is_number(char **str);
int	        ft_atoi(const char *str);
void         print_status(philo_t *p, char *status, char *color);
void        err_msg(char *err_str);
int         parse_and_init(int argc, char** argv);
philo_t     *init_philos(philo_t *p);
int load_args(int argc, char **argv);
long long get_delta_t(long long start_time);
long long get_timestamp(void);
void start_time();
int close_program(philo_t *p);
void start_meal(philo_t *p);
void enter_process(philo_t *p);
void think(philo_t *p);
void _sleep(philo_t *p);
void eat(philo_t *p);
void drop_forks();
void pick_forks(philo_t *p);
void action(int time);
int init_semaphores();
sem_t *open_sem(char* name, int sem_value);


#endif