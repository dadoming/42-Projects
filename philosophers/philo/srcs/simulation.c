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

static void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&table()->mutex.fork[p->hand[LEFT]]);
	pthread_mutex_unlock(&table()->mutex.fork[p->hand[RIGHT]]);
}

static void	pick_forks(t_philo *p)
{
	pthread_mutex_lock(&table()->mutex.fork[p->hand[LEFT]]);
	print_status(p, FORK, WHITE);
	pthread_mutex_lock(&table()->mutex.fork[p->hand[RIGHT]]);
	print_status(p, FORK, WHITE);
}

int	eat(t_philo *p)
{
	if (stop(p) == TRUE)
		return (TRUE);
	pick_forks(p);
	if (stop(p) == TRUE)
		return (TRUE);
	print_status(p, EAT, GREEN);
	ft_usleep(table()->rules.time_eat);
	// if (stop(p) == TRUE)
	// 	return (TRUE);
	p->delta_death = get_delta_t();
	if (stop(p) == TRUE)
		return (TRUE);
	p->times_eaten++;
	if (stop(p) == TRUE)
		return (TRUE);
	drop_forks(p);
	return (FALSE);
}

int	think(t_philo *p)
{
	if (stop(p) == TRUE)
		return (TRUE);
	print_status(p, THINK, MAGENTA);
	return (FALSE);
}

int	_sleep(t_philo *p)
{
	if (stop(p) == TRUE)
		return (TRUE);
	print_status(p, SLEEP, YELLOW);
	ft_usleep(table()->rules.time_sleep);
	if (stop(p) == TRUE)
		return (TRUE);
	return (FALSE);
}
