/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:57:01 by dadoming          #+#    #+#             */
/*   Updated: 2023/04/14 17:11:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(t_win *w, int key)
{
	w->move_count++;
	if (key == ESC)
		key_close_window(w);
	if (key == W && w->map[w->p_y - 1][w->p_x] != '1')
		w -> p_y -= 1;
	if (key == A && w->map[w->p_y][w->p_x - 1] != '1')
		w -> p_x -= 1;
	if (key == D && w->map[w->p_y][w->p_x + 1] != '1')
		w -> p_x += 1;
	if (key == S && w->map[w->p_y + 1][w->p_x] != '1')
		w -> p_y += 1;
	if ((key == D || key == A || key == W || key == S)
		&& w -> map[w->p_y][w->p_x] == 'E' && w -> caught == w -> c)
		exit_game_win(w);
	if (valid_key(key, w) && w->map[w->p_y][w->p_x] == '1')
		w -> move_count -= 1;
	return (1);
}

int	key_event(int key, t_win *w)
{
	printf("key: %d\n", key);
	if (valid_key(key, w))
	{
		if (key_press(w, key))
			put_back(w, key, w->p_x, w->p_y);
		mlx_put_image_to_window(w->mlx, w->win, which_side(w, key),
			w->p_x * w->size_width, w->p_y * w->size_height);
		calculate_str_back(w);
	}
	else
		return (0);
	return (0);
}

int	valid_key(int key, t_win *w)
{
	if (key == W && w->map[w->p_y - 1][w->p_x] != '1')
		return (1);
	if (key == A && w->map[w->p_y][w->p_x - 1] != '1')
		return (1);
	if (key == S && w->map[w->p_y + 1][w->p_x] != '1')
		return (1);
	if (key == D && w->map[w->p_y][w->p_x + 1] != '1')
		return (1);
	if (key == ESC)
		return (1);
	return (0);
}

void	exit_game_win(t_win *w)
{
	msg("You won, yey!");
	w -> map[w->p_y + 1][w->p_x] = '1';
	w -> map[w->p_y][w->p_x + 1] = '1';
	w -> map[w->p_y - 1][w->p_x] = '1';
	w -> map[w->p_y][w->p_x - 1] = '1';
	w -> winn = 1;
	return ;
}
