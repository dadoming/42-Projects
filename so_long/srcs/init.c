/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:38:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/16 01:37:15 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	initialization(t_win *value, char *arg)
{
	if (check_valid_map(arg) != 0)
		error_msg("Map filename is invalid");
	// missing free(map_file)?
	value -> map_file = open(arg, O_RDONLY);
	if (value -> map_file < 0)
		error_msg("Unable to find file");
	value -> map = get_map_table(value -> map_file, value -> map, 0);
	if (!(value -> map))
		error_msg("Couldn't read map");
	// free(tudo)
	get_map_sizes(value);
	if (value -> width <= 2 || value -> height <= 2)
		error_msg("Invalid map sizes");
	// free(tudo)
	if (check_map_positions(value -> map, value, 0, 0) == 0)
		error_msg("Invalid map components");
}

void	load_all_imgs(t_win *w)
{
	w -> wall_image1 = mlx_xpm_file_to_image(w -> mlx, "./sprites/wall.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> floor_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/floor.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> enemy_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/Giovanni.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> exit_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/Exit.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> coin_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/Pokeball1.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> coin_image2 = mlx_xpm_file_to_image(w -> mlx,
			"./sprites/Pokeball2.xpm", &(w -> size_width), &(w -> size_height));
	w -> coin_image3 = mlx_xpm_file_to_image(w -> mlx,
			"./sprites/Pokeball3.xpm", &(w -> size_width), &(w -> size_height));
	w -> p_img_down = mlx_xpm_file_to_image(w -> mlx,
			"./sprites/Gengar_Down.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> p_img_up = mlx_xpm_file_to_image(w -> mlx,
			"./sprites/Gengar_Up.xpm", &(w -> size_width), &(w -> size_height));
	w -> p_img_left = mlx_xpm_file_to_image(w -> mlx,
			"./sprites/Gengar_Left.xpm",
			&(w -> size_width), &(w -> size_height));
	w -> p_img_right = mlx_xpm_file_to_image(w -> mlx,
			"./sprites/Gengar_Right.xpm",
			&(w -> size_width), &(w -> size_height));
}

char	**get_map_table(int fd, char **map, int count)
{
	char	*s;

	s = get_next_line(fd);
	if (s)
		map = get_map_table(fd, map, count + 1);
	if (!map)
		map = malloc(sizeof(char *) * count + 1);
	map[count] = s;
	count++;
	return (map);
}

void	get_map_sizes(t_win *w)
{
	while (w -> map[0][w->width] != '\n')
		w->width++;
	while (w -> map[w->height] != 0)
		w -> height++;
}
