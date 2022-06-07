/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:16:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 21:01:06 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
#define WINDOW_H

typedef struct window_s{
    void *mlx;
    void *win;
    int map_file;
    int height;
    int width;
    char **map;
    int door;
    int p_s_position;
    int zero;
    int one;
}               win_s;

#endif