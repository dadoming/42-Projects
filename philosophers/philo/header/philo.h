#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

# define BOLDRED        "\033[1m\033[31m"
# define GREEN      "\033[32m"
# define BOLDGREEN  "\033[1m\033[32m"
# define YELLOW     "\033[33m"
# define MAGENTA       "\033[35m"
# define WHITE      "\033[37m"
# define RESET		"\033[0m"

# define EAT        "is eating"
# define SLEEP      "is sleeping"
# define THINK      "is thinking"
# define DIED       "died"
# define FORK       "has taken a fork"

# define LEFT       0
# define RIGHT      1

# define TRUE       1
# define FALSE      0

typedef struct s_rules
{
    int p_num;
    int time_eat;
    int time_die;
    int time_sleep;
    int max_eat; 
} t_rules;

typedef struct s_mutex
{
    pthread_mutex_t fork[200];
    pthread_mutex_t write;
    pthread_mutex_t dead;
} t_mutex;

typedef struct s_table
{
    t_rules rules;
    t_mutex mutex;
    long long time_start;
    long long time_end;
    int index_death;
} t_table;

typedef struct s_philo
{
    int index;
    int hand[2];
    int times_eaten;
    long long delta_death;
    pthread_t checker;
} t_philo;


/* Returns the address in memory in
    which table is located*/
t_table *table(void);

/* Checks user input */
int check_input(int argc, char **argv);

/* Inits all memory */
int init_program(int argc, char **argv, t_philo *philo);

/* Gets present time */
long long get_delta_t();

/* Creates and joins threads */
int start_program(t_philo *philo);

/* Destroys mutexes */
void destroy_program();

/* Prints the last program message.
    Either one died or all have full tummy.*/
void print_end();

/* If no philosopher died, prints passed status message. */
void print_status(t_philo *p, char *status, char *color);

/* Monitoring thread to check for the death of a philosopher by comparing
    if has passed more time than time_to_die, if yes set the philo_index
    to the number of the philo that died, which stops all running threads
    using check_end(). */
void*       stop(void *arg);
int         check_end();

/* Simulation functions */
int         eat(t_philo *p);
int         think(t_philo *p);
int         _sleep(t_philo *p);

/* Time functions */
void	    ft_usleep(int time);
void        start_timer();
long long   get_timestamp(void);

/* utils */
long	    ft_atoi(const char *str);
void        err_msg(char *str);

#endif
