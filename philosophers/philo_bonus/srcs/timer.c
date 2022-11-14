/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:31 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 16:13:26 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

void	start_timer(void)
{
	table()->time_start = get_timestamp();
}

long long	get_delta_t(void)
{
	return (get_timestamp() - table()->time_start);
}

void	ft_usleep(int time)
{
	long long	start;

	start = get_timestamp();
	while (get_timestamp() < start + time)
		usleep(10);
}

long long	get_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
