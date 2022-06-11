/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/11 18:55:27 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//mktt
//https://opengameart.org/content/animated-pirate-captain


// Player movement w-13 a-0 s-1 d-2
// int move(int key, win_s *w)
// {
//     if(key == 13)
//     {
//         w -> move_count++;
//         mlx_put_image_to_window(w -> mlx, w -> win, w -> p_img_1, w -> p_x * (w -> size_width), (w -> p_y * (w -> size_height)) - w -> size_height);
//         mlx_put_image_to_window(w -> mlx, w -> win, w -> floor_image, w -> p_x * (w -> size_width), (w -> p_y * (w -> size_height)));
//     }
//     // if(key == 0)
//     // {
        
//     // }
//     // if(key == 1)
//     // {
        
//     // }
//     // if(key == 2)
//     // {
        
//     // }
//     return (key);
// }

int main(int argc, char **argv)
{
    win_s ptr;
    
    if (argc != 2)
        error_msg("Wrong number of arguments");

    // Inits and checks
    initialization(&ptr, argv[1]);

    // Open screen
    ptr.mlx = mlx_init();
    if(!ptr.mlx)
        return(3);

    // Loads images into program
    load_all_imgs(&ptr);

    // Create window with sprite size [32x32]
    ptr.win = mlx_new_window(ptr.mlx, ptr.width * ptr.size_width, ptr.height * ptr.size_height, "so_long");//trocar o tamanho da window 
    if(!ptr.win)
        error_msg("Unable to create window");
    
    // Prints map tiles
    print_initial_map(&ptr);
    
    //ptr.move_count = 0;
    // Moves player
    //mlx_hook(ptr.mlx, 2, 1L<<2, move, &ptr);
    
    // Key event to close window
    mlx_hook(ptr.win, 2, 1L << 0, &key_close_window, &ptr);
    mlx_hook(ptr.win, 17, 1L << 2, &x_close_window, &ptr);
    
    // To keep the key input active
    mlx_loop(ptr.mlx);
    return (0);
}