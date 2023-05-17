/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:36:09 by dadoming          #+#    #+#             */
/*   Updated: 2023/04/14 17:04:04 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_variables(char c)
{
	if (c == '1' || c == '\n' || c == '\0' || c == 'C' || c == '0'
		|| c == 'P' || c == 'E' || c == 'B')
		return (1);
	return (0);
}

int	check_map_positions(char **map, t_win *w, int x, int y)
{
	while (map[y] != 0)
	{
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (check_variables(map[y][x]) == 0)
				return (0);
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

int	check_valid_map(const char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] != '.')
		i--;
	str = str + i;
	return (!ft_strncmp(str, ".ber", 5));
}
