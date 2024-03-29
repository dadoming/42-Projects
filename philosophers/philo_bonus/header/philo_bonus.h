/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:41 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 16:48:18 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <limits.h>

# define BOLDRED    "\033[1m\033[31m"
# define GREEN      "\033[32m"
# define BOLDGREEN  "\033[1m\033[32m"
# define YELLOW     "\033[33m"
# define MAGENTA    "\033[35m"
# define WHITE      "\033[37m"
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
	sem_t	*forks;
	sem_t	*died;
	sem_t	*print;
}	t_semaph;

typedef struct s_rules
{
	int		p_num;
	int		time_eat;
	int		time_die;
	int		time_sleep;
	int		max_eat;
}	t_rules;

typedef struct s_table
{
	t_rules		rules;
	t_semaph	sem;
	long long	time_end;
	long long	time_start;
}	t_table;

typedef struct s_philo
{
	int			index;
	int			times_eaten;
	pid_t		pid;
	pthread_t	checker;
	sem_t		*mutex;
	long long	delta_death;
}	t_philo;

/* main.c */
t_table		*table(void);

/* check_input.c*/
int			check_input(int argc, char **argv);

/* init_program.c */
int			init_program(int argc, char **argv, t_philo *philo);

/* start_program.c */
void		start_program(t_philo *philo);

/* timer.c */
void		start_timer(void);
void		ft_usleep(int time);
long long	get_delta_t(void);
long long	get_timestamp(void);

/* destroy.c */
int			destroy(t_philo *philo);

/* utils.c */
sem_t		*open_sem(char *name, int sem_value);
long		ft_atoi(const char *str);
void		err_msg(char *str);
void		print_status(t_philo *p, char *status, char *color);
char		*_itoa(int n);
int			ft_strlen(const char *str);
char		*_append(char const *s1, char const *s2);

void		*check_death(void *arg);
void		eat(t_philo *p);
int			destroy(t_philo *philo);
void		*free_all(void *arg);

#endif
