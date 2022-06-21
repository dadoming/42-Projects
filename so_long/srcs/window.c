/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:17:53 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/21 04:25:28 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Close window + needs to free(all)
int	x_close_window(t_win *ptr)
{
	mlx_destroy_window (ptr -> mlx, ptr -> win);
	exit(0);
}

// Closes window + needs to free(all)
void	key_close_window(t_win *ptr)
{
	mlx_destroy_window (ptr -> mlx, ptr -> win);
	exit(0);
}
