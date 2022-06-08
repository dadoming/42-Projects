/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/08 15:23:39 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    win_s ptr;
    
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
        
    // Key event to close window
    mlx_hook(ptr.win, 2, 1L << 0, &key_close_window, &ptr);
    mlx_hook(ptr.win, 17, 1L << 2, &x_close_window, &ptr);
    
    // To keep the key input active
    mlx_loop(ptr.mlx);
    return (0);
}