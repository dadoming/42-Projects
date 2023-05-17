/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:43:58 by dadoming          #+#    #+#             */
/*   Updated: 2023/04/14 17:03:53 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_background(t_win *w, int x, int y)
{
	if (w -> map[y][x] == '1')
		mlx_put_image_to_window(w->mlx, w->win, w->wall_image1,
			x * (w->size_width), y * (w->size_height));
	else
		mlx_put_image_to_window(w -> mlx, w -> win, w -> floor_image,
			x * (w -> size_width), y * (w -> size_height));
}

void	print_objects(t_win *w, int x, int y)
{
	if (w -> map[y][x] == 'C')
		mlx_put_image_to_window(w->mlx, w->win, w->coin_image,
			x * (w->size_width), y * (w->size_height));
	else if (w -> map[y][x] == 'E')
	{
		mlx_put_image_to_window(w->mlx, w->win, w->exit_image,
			x * (w->size_width), y * (w->size_height));
	}
	else if (w -> map[y][x] == 'B')
		mlx_put_image_to_window(w->mlx, w->win, w->enemy_image,
			x * (w->size_width), y * (w->size_height));
	else if (w -> map[y][x] == 'P')
	{
		mlx_put_image_to_window(w->mlx, w->win, w->p_img_down,
			x * (w->size_width), y * (w->size_height));
		w -> p_x = x;
		w -> p_y = y;
	}
}

void	print_initial_map(t_win *w, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			print_background(w, x, y);
			if (map[y][x] == 'C' || map[y][x] == 'B' ||
				map[y][x] == 'P' || map[y][x] == 'E')
			{
				print_objects(w, x, y);
			}
			x++;
		}
		y++;
	}
}

void	print_string(t_win *w)
{
	w->m_count = ft_itoa(w->move_count);
	mlx_string_put(w -> mlx, w -> win, 4, 6, 123746, w -> m_count);
	if (w->m_count > 0)
		free(w->m_count);
}
