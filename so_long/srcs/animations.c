/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:17:59 by dadoming          #+#    #+#             */
/*   Updated: 2023/04/14 17:09:41 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	victory(t_win *w)
{
	static int	delay;
	static int	i;

	mlx_put_image_to_window(w->mlx, w->win, w->exit_image,
		w->p_x * w->size_width, w->p_y * w->size_height);
	if (i == 0)
		mlx_put_image_to_window(w->mlx, w->win, w->exit_1,
			w->p_x * w->size_width, w->p_y * w->size_height);
	if (i == 1)
		mlx_put_image_to_window(w->mlx, w->win, w->exit_3,
			w->p_x * w->size_width, w->p_y * w->size_height);
	if (i == 2)
		mlx_put_image_to_window(w->mlx, w->win, w->exit_2,
			w->p_x * w->size_width, w->p_y * w->size_height);
	if (i == 3)
		mlx_put_image_to_window(w->mlx, w->win, w->p_img_down,
			w->p_x * w->size_width, w->p_y * w->size_height);
	i++;
	if (i > 3)
		i = 0;
	if (delay++ > 10)
		ft_exit_game(w);
}

int	loop_engine(t_win *w)
{
	static int	delay;

	if (++delay < 10000)
		return (0);
	if (w -> winn)
		victory(w);
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
		ctrl = 0;
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
		ctrl = 0;
		return (w->coin_image3);
	}
	return (0);
}

void	ball_roll(t_win *w)
{
	int		y;
	int		x;
	void	*helper;

	helper = get_ball_side(w);
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
				mlx_put_image_to_window(w->mlx, w->win, helper,
					x * (w->size_width), y * (w->size_height));
			}
			x++;
		}
		y++;
	}
}

void	calculate_str_back(t_win *w)
{
	int	i;
	int	squares;
	int	num;

	squares = 100;
	num = 1;
	i = 0;
	while (i < w->move_count)
	{
		if (squares == i)
		{
			num++;
			squares *= 10;
		}
		i++;
	}
	i = 0;
	while (i < num)
	{
		mlx_put_image_to_window(w->mlx, w->win, w->wall_image1,
			i * (w->size_width), 0);
		i++;
	}
	print_string(w);
}
