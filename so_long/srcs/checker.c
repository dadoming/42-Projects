/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:36:09 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/15 22:16:19 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to check map variables
int	check_map_positions(char **map, t_win *w, int x, int y)
{
	while (map[y] != 0)
	{
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if ((map[0][x] != '1') || map[w -> height - 1][x] != '1')
				return (0);
			else if (map[y][0] != '1' || map[y][w -> width - 1] != '1')
				return (0);
			if (map[y][x] == 'C')
				w -> c++;
			if (map[y][x] == 'P')
				w -> p++;
			if (map[y][x] == 'E')
				w -> e++;
			x++;
		}
		x = 0;
		y++;
	}
	if (w -> c < 1 || w -> p != 1 || w -> e != 1)
		return (0);
	return (1);
}

// Checks map file name
int	check_valid_map(char *str)
{
	char	**checker;

	if (!strchr(str, '.'))
		return (1);
	checker = ft_split(str, '.');
	if (ft_strncmp(checker[1], "ber", 3) == 0 && !checker[2])
		return (0);
	return (1);
}
