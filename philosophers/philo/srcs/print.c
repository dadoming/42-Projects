/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:07 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 19:44:40 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	print_end(void)
{
	pthread_mutex_lock(&(table()->mutex.write));
	if (table()->is_dead== 0)
		printf("\n%sAll philos ate %d times.\n%s", BOLDGREEN, \
		table()->rules.max_eat, RESET);
	pthread_mutex_unlock(&(table()->mutex.write));
}

int	print_status(t_philo *p, char *status, char *color)
{
	long long	current_time;

	current_time = get_delta_t();
	pthread_mutex_lock(&table()->mutex.write);
	if (table()->is_dead == TRUE || p->times_eaten == table()->rules.max_eat)
	{
		pthread_mutex_unlock(&table()->mutex.write);
		return (TRUE);
	}
	printf("%s%lld\t%d\t%s%s\n", color, current_time, p->index, status, RESET);
	pthread_mutex_unlock(&table()->mutex.write);
	return(FALSE);
}
