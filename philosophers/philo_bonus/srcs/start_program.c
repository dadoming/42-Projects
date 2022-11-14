/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:29 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 16:12:24 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

static int	only_one_sitting(void);
static void	routine(t_philo *philo);

void	*free_all(void *arg)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)arg;
	sem_wait(table()->sem.died);
	i = -1;
	while (++i < table()->rules.p_num)
		kill(p[i].pid, SIGKILL);
	exit(0);
}

void	start_program(t_philo *philo)
{
	int			i;
	pthread_t	free;

	if (only_one_sitting() == TRUE)
		return ;
	i = 0;
	while (i < table()->rules.p_num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			routine(&philo[i]);
		i++;
	}
	pthread_create(&free, NULL, free_all, philo);
	i = 0;
	while (i < table()->rules.p_num)
	{
		waitpid(philo[i].pid, NULL, 0);
		i++;
	}
	pthread_detach(free);
}

static void	routine(t_philo *philo)
{
	int	i;

	if (philo->index % 2 == 0)
		ft_usleep(20);
	pthread_create(&philo->checker, NULL, check_death, philo);
	pthread_detach(philo->checker);
	i = 0;
	while ((i < table()->rules.max_eat) || (table()->rules.max_eat == -1))
	{
		eat(philo);
		i++;
		if (i == table()->rules.max_eat)
		{
			exit(0);
		}
		print_status(philo, SLEEP, YELLOW);
		ft_usleep(table()->rules.time_sleep);
		print_status(philo, THINK, MAGENTA);
	}
}

static int	only_one_sitting(void)
{
	if (table()->rules.p_num == 1)
	{
		start_timer();
		printf("%s%lld\t%d\t%s%s\n", WHITE, \
			get_timestamp() - table()->time_start, 1, FORK, RESET);
		ft_usleep(table()->rules.time_die);
		table()->time_end = get_delta_t();
		printf("\n%s%lld\t1\t%s%s\n", BOLDRED, \
			table()->time_end, DIED, RESET);
		return (TRUE);
	}
	return (FALSE);
}
