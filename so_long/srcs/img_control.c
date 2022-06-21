/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 04:16:19 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/21 04:17:31 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_back(t_win *w, int key, int x, int y)
{
	int	floor_back;

	floor_back = 0;
	if ((key == W && ++floor_back) && w->map[y][x] != '1')
		y += 1;
	if ((key == A && ++floor_back) && w->map[y][x] != '1')
		x += 1;
	if ((key == S && ++floor_back) && w->map[y][x] != '1')
		y -= 1;
	if ((key == D && ++floor_back) && w->map[y][x] != '1')
		x -= 1;
	if (w->map[w->p_y][w->p_x] == 'C')
		catch(w);
	if (w->map[w->p_y][w->p_x] == 'B')
		ft_exit_game(w);
	if (w->map[y][x] == 'E')
	{
		floor_back = 0;
		mlx_put_image_to_window(w->mlx, w->win, w->exit_image,
			x * w->size_width, y * w->size_height);
	}
	if (floor_back)
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

void	*which_side(t_win *w, int key)
{
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
