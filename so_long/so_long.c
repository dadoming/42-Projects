/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 21:16:39 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(1);
    win_s ptr;

    // Init
    if(initialization(&ptr, argv[1]) != 0)
        return(1);

    // Function to check map variables -- prosseguir nesta file -> checker
    // if(check_map_positions(map) == 0)
    // {
    //     //free(tudo)
    //     error_msg("This map does not meet the requirements");
    //     return (2);
    // }
    
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