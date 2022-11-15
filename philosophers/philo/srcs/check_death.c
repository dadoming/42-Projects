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

void	*check(void *args)
{
    t_philo *p;
	long long time_now;

    p = (t_philo *)args;
	while (1)
	{
		time_now = get_delta_t();
		pthread_mutex_lock(&(table()->mutex.check));
		if((time_now - p->delta_death) > table()->rules.time_die)
		{
			print_status(p, DIED, BOLDRED);
			pthread_mutex_lock(&(table()->mutex.death));
        	table()->is_dead = TRUE;
			pthread_mutex_unlock(&(table()->mutex.death));
			pthread_mutex_unlock(&(table()->mutex.check));
			return(NULL) ;
		}
		pthread_mutex_unlock(&(table()->mutex.check));
		pthread_mutex_lock(&(table()->mutex.check));
		if(p->times_eaten == table()->rules.max_eat || table()->is_dead == 1)
		{
			pthread_mutex_unlock(&(table()->mutex.check));
			return(NULL) ;
		}
		pthread_mutex_unlock(&(table()->mutex.check));
	}
	return (NULL);
}
