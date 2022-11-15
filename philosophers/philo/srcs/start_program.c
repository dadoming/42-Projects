/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:03 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 19:42:37 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	only_one_sitting(void);
static int	create_threads(pthread_t *th, t_philo *p);
static int	join_threads(pthread_t *th);
static void	*routine(void *philo);

int	start_program(t_philo *philo)
{
	pthread_t	th[200];

	if (only_one_sitting() == TRUE)
		return (FALSE);
	if (create_threads(th, philo) == TRUE)
		return (TRUE);
	if (join_threads(th) == TRUE)
		return (TRUE);
	return (FALSE);
}

static void	*routine(void *philo)
{
	t_philo	*p;
	pthread_t monitor;
	
	p = (t_philo *)philo;
	if (p->index % 2 == 0)
		ft_usleep(5);
	if(pthread_create(&monitor, NULL, check, p) != 0)
	{
		err_msg("Error creating monitoring thread");
		return(NULL);
	}
	while (eat(p) == FALSE && _sleep(p) == FALSE && think(p) == FALSE)
		continue;
	if(pthread_join(monitor, NULL) != 0)
	{
		err_msg("Error joining monitoring thread");
		return(NULL);
	}
	return (0);
}

static int	create_threads(pthread_t *th, t_philo *p)
{
	int	i;

	i = 0;
	while (i < table()->rules.p_num)
	{
		if (pthread_create(&th[i], NULL, routine, &p[i]) != 0)
		{
			err_msg("Error creating thread");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static int	join_threads(pthread_t *th)
{
	int	i;

	i = 0;
	while (i < table()->rules.p_num)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			err_msg("Error joining thread");
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static int	only_one_sitting(void)
{
	if (table()->rules.p_num == 1)
	{
		printf("%s%lld\t%d\t%s%s\n", WHITE, get_delta_t(), 1, FORK, RESET);
		ft_usleep(table()->rules.time_die);
		printf("%s%lld\t%d\t%s%s\n", BOLDRED, get_delta_t(), 1, DIED, RESET);
		table()->is_dead = 1;
		return (TRUE);
	}
	return (FALSE);
}
