/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:05 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/16 13:35:58 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	pick_forks(t_philo *p)
{
	if (((p->index - 1) % 2) != 0)
	{
		pthread_mutex_lock(&table()->mutex.fork[p->hand[RIGHT]]);
		print_status(p, FORK, WHITE);
		pthread_mutex_lock(&table()->mutex.fork[p->hand[LEFT]]);
		if (print_status(p, FORK, WHITE) == TRUE)
		{
			pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
			pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
			return (TRUE);
		}
	}
	else
	{
		pthread_mutex_lock(&table()->mutex.fork[p->hand[LEFT]]);
		print_status(p, FORK, WHITE);
		pthread_mutex_lock(&table()->mutex.fork[p->hand[RIGHT]]);
		if (print_status(p, FORK, WHITE) == TRUE)
		{
			pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
			pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
			return (TRUE);
		}
	}
	return (FALSE);
}

int	eat(t_philo *p)
{
	if (pick_forks(p) == TRUE)
		return (TRUE);
	if (print_status(p, EAT, GREEN) == TRUE)
	{
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
		return (TRUE);
	}
	ft_usleep(table()->rules.time_eat);
	pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
	pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
	pthread_mutex_lock(&(table()->mutex.check));
	p->delta_death = get_delta_t();
	p->times_eaten++;
	pthread_mutex_unlock(&(table()->mutex.check));
	return (FALSE);
}

int	think(t_philo *p)
{
	if (print_status(p, THINK, MAGENTA) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	_sleep(t_philo *p)
{
	if (print_status(p, SLEEP, YELLOW) == TRUE)
		return (TRUE);
	ft_usleep(table()->rules.time_sleep);
	return (FALSE);
}
