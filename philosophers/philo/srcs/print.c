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
	if (table()->index_death == 0)
		printf("\n%sAll philos ate %d times.\n%s", BOLDGREEN, \
		table()->rules.max_eat, RESET);
	
}

void	print_status(t_philo *p, char *status, char *color)
{
	long long	current_time;

	pthread_mutex_lock(&table()->mutex.write);
	if (stop(p) == TRUE)
	{
		pthread_mutex_unlock(&table()->mutex.write);
		return ;
	}	
	current_time = get_delta_t();
	printf("%s%lld\t%d\t%s%s\n", color, current_time, p->index, status, RESET);
	pthread_mutex_unlock(&table()->mutex.write);
}
