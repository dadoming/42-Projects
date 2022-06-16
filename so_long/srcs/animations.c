/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:17:59 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/16 02:11:57 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Loop hook
int	loop_engine(t_win *w)
{
	static int	delay;

	if (++delay < 5000)
		return (0);
	if ((delay % 5) == 0)
		ball_roll(w);
	delay = 0;
	return (w != 0);
}

void	*get_ball_side(t_win *w)
{
	static int	ctrl;
	static int	check = 1;

	if (ctrl == -1)
	{
		check *= -1;
		ctrl++;
		return (w->coin_image2);
	}
	if (ctrl == 0)
	{
		if (check == 1)
			ctrl++;
		else
			ctrl--;
		return (w->coin_image);
	}
	if (ctrl == 1)
	{
		check *= -1;
		ctrl--;
		return (w->coin_image3);
	}
	return (0);
}

void	ball_roll(t_win *w)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			if (w -> map[y][x] == 'C')
			{
				mlx_put_image_to_window(w->mlx, w->win, w->floor_image,
					x * (w->size_width), y * (w->size_height));
				mlx_put_image_to_window(w->mlx, w->win, get_ball_side(w),
					x * (w->size_width), y * (w->size_height));
			}
			x++;
		}
		y++;
	}
}

void	string_on_screen(t_win *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->wall_image1, 0, 0);
	if (w->move_count > 100)
		mlx_put_image_to_window(w->mlx, w->win, w->wall_image1, 32, 0);
	w->m_count = ft_itoa(w->move_count);
	mlx_string_put(w -> mlx, w -> win, 8, 8, 123746, w -> m_count);
}
