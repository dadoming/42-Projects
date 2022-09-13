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


typedef struct s_rules
{
    int             nr_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             x_eats;

}   t_rules;

typedef struct s_table
{
    t_rules         rules;
    long long int   time_start;
    sem_t           *forks;

}   t_table;

typedef struct s_philo
{
    int             index;
    int             x_eaten;
    t_table         *table;

}   t_philo;


/*
**  main.c
*/
t_table     *table(void);

int         check_if_is_number(char **str);
int	        ft_atoi(const char *str);
void        err_msg(char *err_str);
int         parse_and_init(int argc, char** argv);
t_philo     *init_philos(t_philo *p);



#endif