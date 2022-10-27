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
#include <limits.h>

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

# define TRUE       1
# define FALSE      0

typedef struct s_semaph
{
    sem_t   *forks;
    sem_t   *died;
    sem_t   *print;
}   t_semaph;

typedef struct s_rules
{
    int p_num;
    int time_eat;
    int time_die;
    int time_sleep;
    int max_eat;
}   t_rules;

typedef struct s_table
{
    t_rules rules;
    t_semaph sem;
    long long   time_start;
    long long   time_end;
    int         index_death;
} t_table;

typedef struct s_philo
{
    int index;
    int is_dead;
    int times_eaten;
    long long delta_death;
    pid_t pid;
} t_philo;

/* main.c */
t_table *table(void);

/* check_input.c*/
int check_input(int argc, char **argv);

/* init_program.c */
int init_program(int argc, char **argv, t_philo *philo);

/* start_program.c */
void start_program(t_philo *philo);

/* timer.c */
void start_timer();
long long get_delta_t();
long long get_timestamp(void);
void action(long long timer);

/* destroy.c */
int close_semaphores();

/* utils.c */
long	ft_atoi(const char *str);
void err_msg(char *str);
void print_status(t_philo *p, char *status, char *color);

void *check_death(void *arg);
int eat(t_philo *p);
void pick_forks(t_philo *p);
void kill_all(t_philo *p);

#endif