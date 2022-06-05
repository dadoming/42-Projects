/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/05 18:20:17 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include "window.h"

/*

    Compile:
    |________  gcc -I /usr/local/include so_long.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

    Manual entry for MiniLibX functions:

    |mlx_init                            -> man /usr/share/man/man3/mlx.1
    |.... Initialization and Necessities
    |
    |manage windows                      -> man /usr/share/man/man3/mlx_new_window.1
    |.... New window
    |.... Clear window
    |.... Destroy window
    |
    |manipulate images                   -> man /usr/share/man/man3/mlx_new_image.1
    |.... New images
    |.... Store color inside images
    |.... XPM images
    |
    |draw inside window                  -> man /usr/share/man/man3/mlx_pixel_put.1
    |.... Color management
    |.... PixelPut and StringPut
    |
    |handle keyboard or mouse events     -> man /usr/share/man/man3/mlx_loop.1

*/

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int key_press(int key, void *o)
{
    (void) o;
    return key;
}

int main(void)
{
    win_l *ptr = NULL;

    //  Title screen
    ptr -> mlx = mlx_init();
    if(!ptr -> mlx)
        return(1);
    ptr -> win = mlx_new_window(ptr -> mlx, 800, 500, "so_long");
    if(!ptr -> win)
        return 2;
    // t_data	img;
    // img.img = mlx_new_image(ptr.mlx, 800, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 400, 250, 0x009966FF);
    // mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
    
    int key = mlx_key_hook(ptr -> win, key_press, 0);
    printf("%d\n", key);
    if(key == 53)
    {
        mlx_clear_window (ptr -> mlx, ptr -> win);
        mlx_destroy_window (ptr -> mlx, ptr -> win);
    }
    mlx_loop(ptr -> mlx);
    
    
    
    
    
    
    return (0);
}