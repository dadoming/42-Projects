/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:11 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 18:16:11 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	init_rules(int argc, char **argv);
static void	init_mutexes(void);
static void	init_philos(t_philo *philo);

int	init_program(int argc, char **argv, t_philo *philo)
{
	if (init_rules(argc, argv) == TRUE)
	{
		err_msg("Something is wrong with the input values");
		return (TRUE);
	}
	init_mutexes();
	init_philos(philo);
	return (FALSE);
}

static void	init_mutexes(void)
{
	int	i;

	i = 0;
	while (i < table()->rules.p_num)
	{
		pthread_mutex_init(&(table()->mutex.fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(table()->mutex.check), NULL);
	pthread_mutex_init(&(table()->mutex.death), NULL);
	pthread_mutex_init(&(table()->mutex.write), NULL);
}

static int	init_rules(int argc, char **argv)
{
	table()->rules.max_eat = 1;
	table()->rules.p_num = ft_atoi(argv[1]);
	table()->rules.time_die = ft_atoi(argv[2]);
	table()->rules.time_eat = ft_atoi(argv[3]);
	table()->rules.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table()->rules.max_eat = ft_atoi(argv[5]);
	if ((table()->rules.p_num < 1 || table()->rules.p_num > 200)
		|| (table()->rules.time_die <= 0) || (table()->rules.time_eat <= 0)
		|| (table()->rules.time_sleep <= 0) || (table()->rules.max_eat <= 0))
		return (TRUE);
	if (argc == 5)
		table()->rules.max_eat = -1;
	return (FALSE);
}

static void	init_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table()->rules.p_num)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].index = i + 1;
		philo[i].hand[LEFT] = i;
		philo[i].hand[RIGHT] = i + 1;
		philo[i].delta_death = table()->rules.time_die;
		philo[i].times_eaten = 0;
		if (i == table()->rules.p_num - 1)
			philo[i].hand[RIGHT] = 0;
		i++;
	}
}
