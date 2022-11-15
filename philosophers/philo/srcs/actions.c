/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:05 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 19:40:08 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int actions(t_philo *p)
{
	if (eat(p) != FALSE)
		return (TRUE); 
	if (table()->rules.max_eat != p->times_eaten)
	{
		if((_sleep(p) != FALSE) || (think(p) != FALSE))
			return(TRUE);
	}
	return (FALSE);
}

static int	pick_forks(t_philo *p)
{
	pthread_mutex_lock(&table()->mutex.fork[p->hand[LEFT]]);
	if (print_status(p, FORK, WHITE) == TRUE)
	{
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
		return (TRUE);
	}
	pthread_mutex_lock(&table()->mutex.fork[p->hand[RIGHT]]);
	if (print_status(p, FORK, WHITE) == TRUE)
	{
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
		return (TRUE);
	}
	return (FALSE);
}

int	eat(t_philo *p)
{
	if(pick_forks(p) == TRUE)
		return (TRUE);
	if(print_status(p, EAT, GREEN) == TRUE)
	{
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
		pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
		return (TRUE);
	}
	ft_usleep(table()->rules.time_eat);
	pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
	pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
	pthread_mutex_lock(&(table()->mutex.check[p->index-1]));
	p->delta_death = get_delta_t();
	p->times_eaten++;
	pthread_mutex_unlock(&(table()->mutex.check[p->index-1]));
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
