/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/09 15:56:21 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(win_s *w, img_s *img)
{
    img -> wall_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/wall_32x32_.xpm", &(img -> x), &(img -> y));
    img -> floor_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/floor_32x32_.xpm", &(img -> x), &(img -> y));

    int i = 0;
    int j = 0;
    int counter_not_printed = 0;
    while(i < w -> width)
    {
        while (j < w -> height)
        {
            if(w -> map[i][j] == '1')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> wall_image, i * (img -> x), j * (img -> y));
            }
            else if(w -> map[i][j] == '0')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> floor_image, j * (img -> x), i * (img -> y));
            }
            else
                counter_not_printed++;
            j++;
        }
        j = 0;
        i++;
    }

}

int main(int argc, char **argv)
{
    win_s ptr;
    img_s img;
    
    if (argc != 2)
        exit(1);

    // Init
    if(initialization(&ptr, argv[1]) != 0)
        return(1);

    // Open screen
    ptr.mlx = mlx_init();
    if(!ptr.mlx)
        return(3);

    // Create window with calculated needed size format
    ptr.win = mlx_new_window(ptr.mlx, 32 * ptr.width, 32 * ptr.height, "so_long");//trocar o tamanho da window 
    if(!ptr.win)
        return (4);
    
    print_map(&ptr, &img);
     
    
    // Key event to close window
    mlx_hook(ptr.win, 2, 1L << 0, &key_close_window, &ptr);
    mlx_hook(ptr.win, 17, 1L << 2, &x_close_window, &ptr);
    
    // To keep the key input active
    mlx_loop(ptr.mlx);
    return (0);
}