/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:36:09 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 21:15:05 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to check map variables
// int check_map_positions()
// {
    
// }

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
