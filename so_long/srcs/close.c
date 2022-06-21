/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:30:34 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/21 20:09:53 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_win *w)
{
	mlx_destroy_image(w->mlx, w->exit_3);
	mlx_destroy_image(w->mlx, w->exit_2);
	mlx_destroy_image(w->mlx, w->exit_1);
	mlx_destroy_image(w->mlx, w->exit_image);
	mlx_destroy_image(w->mlx, w->coin_image3);
	mlx_destroy_image(w->mlx, w->coin_image2);
	mlx_destroy_image(w->mlx, w->coin_image);
	mlx_destroy_image(w->mlx, w->floor_image);
	mlx_destroy_image(w->mlx, w->enemy_image);
	mlx_destroy_image(w->mlx, w->wall_image1);
	mlx_destroy_image(w->mlx, w->p_img_up);
	mlx_destroy_image(w->mlx, w->p_img_down);
	mlx_destroy_image(w->mlx, w->p_img_left);
	mlx_destroy_image(w->mlx, w->p_img_right);
}

void	free_map(t_win *w)
{
	int	i;

	i = 0;
	while (w -> map[i] != 0)
	{
		free(w-> map[i]);
		i++;
	}
	free(w->map[i]);
}

void	ft_exit_game(t_win *w)
{
	if (w -> map_file)
		close(w->map_file);
	if (w -> map)
		free_map(w);
	if (w->win)
		mlx_destroy_window(w->mlx, w->win);
	if ((w->sprites_loaded) == 1)
		free_sprites(w);
	//system("leaks so_long");
	exit(0);
}
