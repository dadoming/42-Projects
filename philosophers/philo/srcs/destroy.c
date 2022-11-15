/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:13 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 17:37:25 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	destroy_program(void)
{
	int	i;

	i = 0;
	if (table()->mutex.fork)
	{
		while (i < table()->rules.p_num)
		{
			pthread_mutex_destroy(&(table()->mutex.fork[i]));
			i++;
		}
	}
	pthread_mutex_destroy(&(table()->mutex.check));
	pthread_mutex_destroy(&(table()->mutex.death));
	pthread_mutex_destroy(&(table()->mutex.write));
}
