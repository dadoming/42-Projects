/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:20 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 16:00:21 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

static void	print_dead(t_philo *p, long long time_now);

void	*check_death(void *arg)
{
	t_philo		*p;
	long long	time_now;

	p = (t_philo *) arg;
	while (1)
	{
		time_now = get_delta_t();
		sem_wait(p->mutex);
		if ((time_now - p->delta_death) > table()->rules.time_die)
		{
			sem_wait(table()->sem.print);
			print_dead(p, time_now);
			sem_post(table()->sem.died);
			break ;
		}
		if (p->times_eaten == table()->rules.max_eat)
			break ;
		sem_post(p->mutex);
		ft_usleep(2);
	}
	return (NULL);
}

static void	print_dead(t_philo *p, long long time_now)
{
	printf("\n%s%lld\t%d\tdied%s\n", BOLDRED, \
			time_now, p->index, RESET);
}
