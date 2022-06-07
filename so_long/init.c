/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:38:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 21:23:56 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

// Initializes variables upon verification
int initialization(win_s *value, char *arg)
{
    // Checks map file name
    if (check_valid_map(arg) != 0)
    {
        error_msg("Wrong input");
        return (1);
    }
    
    // Read file
    value -> map_file = open(arg, O_RDONLY);
    if(value -> map_file < 0)
    {
        //free(map_file)?
        error_msg("Wrong map file input");
        return(2);
    }
    
    // Get map in table
    value -> map = NULL;
    value -> map = get_map_table(value -> map_file, value -> map, 0);
    
    // Function to calculate height and width
    get_map_sizes(value);
    if(value -> width <= 2 || value -> height <= 2)
    {
        //free(tudo)
        error_msg("Your map size does not meet the requirements");
        return (3);
    }

    return(0);
}
