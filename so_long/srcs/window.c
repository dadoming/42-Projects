/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:17:53 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/21 19:00:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Close window + needs to free(all)
int	x_close_window(t_win *ptr)
{
	msg("Exited game");
	ft_exit_game(ptr);
	return (0);
}

void	key_close_window(t_win *ptr)
{
	msg("Exited game");
	ft_exit_game(ptr);
}
