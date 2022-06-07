/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:17:53 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 20:50:55 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Close window + needs to free(all)
int x_close_window(win_s *ptr)
{
    mlx_clear_window (ptr -> mlx, ptr -> win);
    mlx_destroy_window (ptr -> mlx, ptr -> win);
    exit(0);
}

// Closes window + needs to free(all)
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
