/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/06 22:38:51 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Close window + needs to free everything
int x_close_window(win_s *ptr)
{
    mlx_clear_window (ptr -> mlx, ptr -> win);
    mlx_destroy_window (ptr -> mlx, ptr -> win);
    exit(0);
}

int key_close_window(int key, win_s *ptr)
{
    if(key == 53)
    {
        mlx_clear_window (ptr -> mlx, ptr -> win);
        mlx_destroy_window (ptr -> mlx, ptr -> win);
        exit(0);
    }
    return(0);
}


//int argc, char **argv

/*
Um mapa é um conjunto de caracteres:
0 -> empty space
1 -> wall
C -> collectible
E -> map exit
P -> player starting position
*/

int main(int argc, char **argv)
{
    (void) argc;
    
    win_s ptr;
    //void *img;
    //char *path_ground = "./floor_32x32.xpm";
    //int img_width;
    //int img_height;
    

    /*
        preciso de descobrir a quantidade de memoria que preciso
        de alojar
        neste caso
        char **map;
        map = (char **)malloc(height_of_file)
    */

    // Reads and prints map on terminal
    int map_file = open(argv[1], O_RDONLY);
    int i = 0;
    while (i < 9)
    {
        printf("%s", get_next_line(map_file));
        i++;
    }

    // Open screen
    ptr.mlx = mlx_init();
    if(!ptr.mlx)
        return(1);

    // Create window map1 16height 8width
    ptr.win = mlx_new_window(ptr.mlx, 800, 400, "so_long");
    if(!ptr.win)
        return (2);

    // Load image to variable
    // img_height = 32;
    // img_width = 32;
    // img = mlx_xpm_file_to_image(ptr.mlx, path_ground, &img_width, &img_height);

    // Print image to window
    // while(i < 16)
    // {
    //     if(!(mlx_put_image_to_window(ptr.mlx, ptr.win, img, 32, 32)))
    //         return(3);
    // }

    // Key event to close window
    mlx_hook(ptr.win, 2, 1L << 0, &key_close_window, &ptr);
    mlx_hook(ptr.win, 17, 1L << 2, &x_close_window, &ptr);

    // To keep the key input active
    mlx_loop(ptr.mlx);

    return (0);
}