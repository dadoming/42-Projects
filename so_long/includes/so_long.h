/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:41 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/11 18:41:43 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct window_s{
    void *mlx;
    void *win;
    int map_file;
    char **map;
    
    int p_x; //player x
    int p_y; //player y

    //img_size
    int size_width;
    int size_height;

    //images
    void *bomb_image;
    void *wall_image;
    void *floor_image;
    void *coin_image;
    void *exit_image;
    void *p_img_1;
    void *p_img_2;
    void *p_img_3;
    void *p_img_4;
    void *p_img_5;

    int move_count;

    // map values variables
    int width;
    int height;

    int c;//collectible
    int p;//player starting position
    int e;//exit
    
}   win_s;

// checker.c
int check_valid_map(char *str);
int check_map_positions(char **map, win_s *w, int x, int y);

// window.c
int key_close_window(int key, win_s *ptr);
int x_close_window(win_s *ptr);

// error.c
void error_msg(char *str);

// init.c
int initialization(win_s *value, char *arg);
void load_all_imgs(win_s *w);
char **get_map_table(int fd, char **map, int count);
void get_map_sizes(win_s *w);

// print.c
void print_initial_map(win_s *w);

#endif