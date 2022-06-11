/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:38:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/11 18:32:35 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initializes library variables upon verification
int initialization(win_s *value, char *arg)
{
    // Checks map's input name
    if (check_valid_map(arg) != 0)
        error_msg("Map filename is invalid");
    
    // Opens .ber file
    // missing free(map_file)?
    value -> map_file = open(arg, O_RDONLY);
    if(value -> map_file < 0)
        error_msg("Unable to find file");
    
    // Get the map array
    value -> map = NULL;
    value -> map = get_map_table(value -> map_file, value -> map, 0);
    if(!(value -> map))
        error_msg("Couldn't read map");
    
    // Calculate height and width
    // free(tudo)
    get_map_sizes(value);
    if(value -> width <= 2 || value -> height <= 2)
        error_msg("Invalid map sizes");

    // Check map variables
    // free(tudo)
    if(check_map_positions(value -> map, value, 0, 0) == 0)
        error_msg("Invalid map components");
    return(0);
}

// Loads all static images into program
void load_all_imgs(win_s *w)
{
    w -> floor_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/sand.xpm", &(w -> size_width), &(w -> size_height));
    w -> wall_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/water.xpm", &(w -> size_width), &(w -> size_height));
    w -> coin_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/coin.xpm", &(w -> size_width), &(w -> size_height));
    w -> bomb_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/bomb.xpm", &(w -> size_width), &(w -> size_height));
    w -> exit_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/boat_l-r.xpm", &(w -> size_width), &(w -> size_height));
    w -> p_img_1 = mlx_xpm_file_to_image(w -> mlx, "./sprites/Pirate_1_idle.xpm", &(w -> size_width), &(w -> size_height));
    // img -> p_img_2 = mlx_xpm_file_to_image(w -> mlx, "./sprites/Pirate_2_idle.xpm", &(img -> width), &(img -> height));
    // img -> p_img_3 = mlx_xpm_file_to_image(w -> mlx, "./sprites/Pirate_3_idle.xpm", &(img -> width), &(img -> height));
    // img -> p_img_4 = mlx_xpm_file_to_image(w -> mlx, "./sprites/Pirate_4_idle.xpm", &(img -> width), &(img -> height));
    // img -> p_img_5 = mlx_xpm_file_to_image(w -> mlx, "./sprites/Pirate_5_idle.xpm", &(img -> width), &(img -> height));
}

// Returns map as **map
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

// Calculate height and width
void get_map_sizes(win_s *w)
{
    w -> width = 0;
    while(w -> map[0][w->width] != '\n')
        w->width++;
    w -> height = 0;
    while (w -> map[w->height] != 0)
        w -> height++;
}
