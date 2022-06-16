/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:57:01 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/16 02:05:00 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_back(t_win *w, int key, int x, int y)
{
	if (key == W)
		y += 1;
	if (key == A)
		x += 1;
	if (key == S)
		y -= 1;
	if (key == D)
		x -= 1;
	if (w -> map[y][x] == 'E')
		return ;
	if (w->map[w->p_y][w->p_x] == 'C')
		catch(w);
	mlx_put_image_to_window(w->mlx, w->win, w->floor_image,
		x * w->size_width, y * w->size_height);
}

void	catch(t_win *w)
{
	w->map[w->p_y][w->p_x] = '0';
	mlx_put_image_to_window(w->mlx, w->win, w->floor_image,
		w->p_x * w->size_width, w->p_y * w->size_height);
	w->caught++;
}

// Something is wrong here
void	win(t_win *w)
{
	w->map[w->p_y][w->p_x] = '0';
	// mlx_clear_window(w->mlx, w->win);
	// mlx_string_put(w->mlx, w->win, w->size_width * w-> width / 2,
	// 	w->size_height * w-> height / 2, 123547, "GANHOU");
	return ;
}

// Acabar
void	bomb(t_win *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->p_img_down,
		w->p_x * w->size_width, w->p_y * w->size_height);
	exit(0);
}

void	*which_side(t_win *w, int key)
{
	w->move_count++;
	if (key == W)
		return (w->p_img_up);
	if (key == A)
		return (w->p_img_left);
	if (key == S)
		return (w->p_img_down);
	if (key == D)
		return (w->p_img_right);
	return (NULL);
}

int	key_event(int key, t_win *w)
{
	int	floor_back;

	floor_back = 0;
	if (key == ESC)
		key_close_window(w);
	if (key == W && w->map[w->p_y - 1][w->p_x] != '1' && ++floor_back)
		w -> p_y -= 1;
	if (key == A && w->map[w->p_y][w->p_x - 1] != '1' && ++floor_back)
		w -> p_x -= 1;
	if (key == D && w->map[w->p_y][w->p_x + 1] != '1' && ++floor_back)
		w -> p_x += 1;
	if (key == S && w->map[w->p_y + 1][w->p_x] != '1' && ++floor_back)
		w -> p_y += 1;
	if (w->map[w->p_y][w->p_x] == 'B')
		bomb(w);
	if (floor_back)
		put_back(w, key, w->p_x, w->p_y);
	mlx_put_image_to_window(w->mlx, w->win, which_side(w, key),
		w->p_x * w->size_width, w->p_y * w->size_height);
	if (w->caught == w -> c && w->map[w->p_y][w->p_x] == 'E')
	{
		win(w);
	}
	string_on_screen(w);
	return (key);
}
