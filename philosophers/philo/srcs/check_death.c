/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:18 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 19:41:49 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	death_values(t_philo *p, long long int time_now);
static int	ate_all(t_philo *p);

int	stop(t_philo *p)
{
	long long	time_now;

	pthread_mutex_lock(&table()->mutex.check);
	if (check_end() == TRUE || ate_all(p) || table()->is_ddead == 1)
	{
		pthread_mutex_unlock(&table()->mutex.check);
		return(TRUE);
	}
	time_now = get_delta_t();
	if (((time_now - p->delta_death) > table()->rules.time_die) && \
		(table()->index_death == 0))
	{
		death_values(p, time_now);
		pthread_mutex_unlock(&table()->mutex.check);
		return(TRUE);
	}
	pthread_mutex_unlock(&table()->mutex.check);
	return 0;
}

int	check_end(void)
{
	if (table()->index_death > 0)
	{
		return (TRUE);
	}
	return (FALSE);
}

static void	death_values(t_philo *p, long long int time_now)
{
	pthread_mutex_lock(&table()->mutex.dead);
	table()->is_ddead = 1;
	table()->time_end = time_now;
	table()->index_death = p->index;
	printf("\n%s%lld\t%d\tdied\n%s", BOLDRED, table()->time_end, \
		table()->index_death, RESET);
	pthread_mutex_unlock(&table()->mutex.dead);
}

static int	ate_all(t_philo *p)
{
	if ((table()->rules.max_eat > 0) && \
		(p->times_eaten >= table()->rules.max_eat))
		{
			p->ate_all_meals = 1;
			return (TRUE);	
		}
	return (FALSE);
}
