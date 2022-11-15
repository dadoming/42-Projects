/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:25:09 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 18:35:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

int	main(int argc, char **argv)
{
	t_philo	philo[200];

	if (check_input(argc, argv) == TRUE)
		return (1);
	if (init_program(argc, argv, philo) == TRUE)
		return (2);
	start_timer();
	if (start_program(philo) == TRUE)
		return (3);
	ft_usleep(1500);
	print_end();
	destroy_program();
	return (0);
}
