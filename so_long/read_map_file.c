/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:15:09 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 21:06:08 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Returns input map as a Table
char **get_map_table(int fd, char **map, int count)
{
    char *s;

    s = get_next_line(fd);
    if (s)
       map = get_map_table(fd, map, count + 1);
    if (!map)
        map = malloc(sizeof(char *) * count + 1);
    map[count] = s;
    count++;
    return(map);
}

// Function to calculate height and width
void get_map_sizes(win_s *w)
{
    w -> width = 0;
    while(w -> map[0][w->width] != '\n')
        w->width++;
    w -> height = 0;
    while (w -> map[w->height] != 0)
        w -> height++;
}