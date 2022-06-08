/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:36:09 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/08 16:01:19 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to check map variables
int check_map_positions(char **map, win_s *w)
{
    int i;
    int j;
    int c;
    int p;
    int e;

    c = 0;
    p = 0;
    e = 0;
    i = 0;
    j = 0;
    while (map[i] != 0)
    {
        while(map[i][j] != '\n' && map[i][j] != '\0')
        {
            if((map[0][j] != '1') || map[w -> height - 1][j] != '1')
            {
                error_msg("erro no 1 ou ult\n");
                return (0);
            }
            else if(map[i][0] != '1' || map[i][w -> width - 1] != '1')
            {
                error_msg("erro 1 do meio");
                return (0);
            }
            if(map[i][j] == 'C')
            {
                c++;
            }
            if(map[i][j] == 'P')
            {
                p++;
            }
            if(map[i][j] == 'E')
            {
                e++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    if(c < 1 || p != 1 || e != 1)
    {
        error_msg("Invalid component amount");
        return (0);
    }
    return (1);
}

// Checks map file name
int check_valid_map(char *str)
{
    char **checker;

    if (!strchr(str, '.'))
        return (1);
    checker = ft_split(str, '.');
    if(ft_strncmp(checker[1], "ber", 3) == 0 && !checker[2])
        return(0);
    return(1);
}
