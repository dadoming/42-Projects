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
		pthread_mutex_lock(&(table()->mutex.check[p->index-1]));
		if((time_now - p->delta_death) > table()->rules.time_die)
		{
			pthread_mutex_unlock(&(table()->mutex.check[p->index-1]));
			print_status(p, DIED, BOLDRED);
        	table()->is_dead = TRUE;
			break ;
		}
		pthread_mutex_unlock(&(table()->mutex.check[p->index-1]));
		pthread_mutex_lock(&(table()->mutex.check[p->index-1]));
		if(p->times_eaten == table()->rules.max_eat)
		{
			pthread_mutex_unlock(&(table()->mutex.check[p->index-1]));
			break ;
		}
		pthread_mutex_unlock(&(table()->mutex.check[p->index-1]));
		ft_usleep(1);
	}
	return (NULL);
}








/*

void	*check(void *args)
{
	int		i;
    t_philo *p;

    p = (t_philo *)args;
	i = 0;
	if (table()->rules.max_eat > 0)
	{
		while (table()->rules.max_eat > p[i].times_eaten \
			&& table()->is_dead == FALSE)
		{
            if (death(&p[i]) == TRUE)
				break ;
            i++;
            if (i == table()->rules.p_num)
		        i = 0;
		}
	}
	else
	{
		while (table()->is_dead == FALSE)
		{
			if (death(&p[i]) == TRUE)
				break ;
            i++;
            if (i == table()->rules.p_num)
		        i = 0;
        }
	}
	return (NULL);
}

int	death(t_philo *p)
{
	int	time;

	time = get_delta_t();
	pthread_mutex_lock(&(p->check));
    if ((time - p->delta_death) > table()->rules.time_die)
	{
		pthread_mutex_unlock(&(p->check));
		print_status(p, DIED, BOLDRED);
        table()->is_dead = TRUE;
		return (TRUE);
	}
	pthread_mutex_unlock(&(p->check));
	return (FALSE);
}
*/
