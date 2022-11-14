/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:25 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 17:33:27 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

static int	init_rules(int argc, char **argv);
static int	init_philos(t_philo *philo);
static int	init_semaphores(void);

int	init_program(int argc, char **argv, t_philo *philo)
{
	if (init_rules(argc, argv) == TRUE)
	{
		err_msg("Something is wrong with the input values");
		return (TRUE);
	}
	if (init_semaphores() == TRUE)
	{
		destroy(philo);
		return (TRUE);
	}
	if (init_philos(philo) == TRUE)
	{
		err_msg("Error initializing philosophers");
	}
	return (FALSE);
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
	if ((table()->rules.p_num < 1 || table()->rules.p_num > 200) \
		|| (table()->rules.time_die <= 0) \
		|| (table()->rules.time_eat <= 0) \
		|| (table()->rules.time_sleep <= 0) \
		|| (table()->rules.max_eat <= 0))
		return (TRUE);
	if (argc == 5)
		table()->rules.max_eat = -1;
	return (FALSE);
}

static int	init_semaphores(void)
{
	(table())->sem.forks = open_sem("forks", table()->rules.p_num);
	(table())->sem.print = open_sem("print", 1);
	(table())->sem.died = open_sem("forks", 0);
	if ((table())->sem.forks == SEM_FAILED || \
		(table())->sem.died == SEM_FAILED || \
		(table())->sem.print == SEM_FAILED)
	{
		err_msg("Failed opening semaphores");
		return (TRUE);
	}
	return (FALSE);
}

static int	init_mutex(t_philo *p, int i)
{
	char	*str;
	char	*num;

	str = "mutex";
	num = NULL;
	num = _itoa(i);
	str = _append(str, num);
	p->mutex = open_sem(str, 1);
	if (p->mutex == SEM_FAILED)
		return (TRUE);
	free(str);
	free(num);
	return (FALSE);
}

static int	init_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table()->rules.p_num)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].index = i + 1;
		philo[i].delta_death = table()->rules.time_die;
		philo[i].times_eaten = 0;
		if (init_mutex(&philo[i], i) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
