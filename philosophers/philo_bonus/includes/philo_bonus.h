#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
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
    sem_t           *print;
    sem_t           *died;
    sem_t           *stop;

}   semaph_t;

// Shared Values
typedef struct table_s
{
    long long int   time_start;
    int             died;
    int             ate_all;
    rules_t         rules;
    semaph_t        semaphore;

}   table_t;

typedef struct philo_s
{
    int             index;
    int             x_eaten;
    long long int   t_left_after_eat;
    pthread_t       th;
    pid_t           pid;
    table_t         *table;

}   philo_t;

/*
**  main.c
*/
table_t             *table(void);
void                enter_process(philo_t *p);
void                start_meal(philo_t *p);
void                *routine(void *arg);
void kill_process(philo_t *p);

/*
**  sems.c
*/
sem_t               *open_sem(char* name, int sem_value);
int                 init_semaphores();


/*
**  time.c
*/
long long           get_delta_t(long long start_time);
long long           get_timestamp(void);

/*
**  parse_and_init.c
*/
void                init_shared();
philo_t             *init_philos(philo_t *p);
int                 load_args(int argc, char **argv);
int                 parse_and_init(int argc, char** argv);

/*
**  utils.c
*/
int	                ft_atoi(const char *str);
int                 check_if_is_number(char **str);
void                print_status(philo_t *p, char *status, char *color);
void                action(int time);
void                err_msg(char *err_str);

/*
**  close.c
*/
int                 close_program(philo_t *p);

/*
**  actions.c
*/
int                 eat(philo_t *p);
int                _sleep(philo_t *p);
int                think(philo_t *p);


/*
**  death.c
*/
void                *death_check(void *philo);

#endif