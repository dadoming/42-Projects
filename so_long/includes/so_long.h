/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:41 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/07 21:16:35 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "window.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// checker.c
int check_valid_map(char *str);


// window.c
int key_close_window(int key, win_s *ptr);
int x_close_window(win_s *ptr);

// read_map_files.c
char **get_map_table(int fd, char **map, int count);
void get_map_sizes(win_s *w);

// error.c
void error_msg(char *str);

// init.c
int initialization(win_s *value, char *arg);



#endif