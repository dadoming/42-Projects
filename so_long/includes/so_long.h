/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:41 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/16 02:16:04 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_window{
	// Mlx pointer
	void	*mlx;

	// Window pointer
	void	*win;

	// Player position
	int		p_x;
	int		p_y;

	// Img size
	int		size_width;
	int		size_height;

	// Map
	int		map_file;
	char	**map;

	// Map values variables
	int		width;
	int		height;

	// Map sprites
	void	*wall_image1;
	void	*enemy_image;
	void	*floor_image;
	void	*coin_image;
	void	*coin_image2;
	void	*coin_image3;
	void	*exit_image;

	// Player images
	void	*p_img_up;
	void	*p_img_down;
	void	*p_img_left;
	void	*p_img_right;

	// Move counter
	int		move_count;
	char	*m_count;

	// Object amount
	int		caught;
	int		c;
	int		p;
	int		e;
}	t_win;

/* <<< checker.c >>> */
//
// Checks map's input name
int		check_valid_map(char *str);
// Check map variables
int		check_map_positions(char **map, t_win *w, int x, int y);

/* <<< window.c >>> */
//
// Key event to close window
void	key_close_window(t_win *ptr);
// Event to close window on red cross 
int		x_close_window(t_win *ptr);

/* <<< init.c >>> */
//
// Initializes library variables upon verification
void	initialization(t_win *value, char *arg);
// Loads all images into program
void	load_all_imgs(t_win *w);
// Get the map **
char	**get_map_table(int fd, char **map, int count);
// Calculate height and width
void	get_map_sizes(t_win *w);

/* <<< print.c >>> */
//
// Prints background
void	print_background(t_win *w, int x, int y);
//Prints objects
void	print_objects(t_win *w, int x, int y);
// Prints inital map
void	print_initial_map(t_win *w, char **map);

/* <<< move.c >>> */
//
// Checks if the key can be accessed and
// Clears player tile
void	put_back(t_win *w, int key, int x, int y);
// Sets floored tile to 0 and prints floor when ball caught
void	catch(t_win *w);
// Wins game
void	win(t_win *w);
// Loses game
void	bomb(t_win *w);
// chooses the right action according to that
int		key_event( int key, t_win *w);
// Changes image to the player side
void	*which_side(t_win *w, int key);

/* <<< animations.c >>>*/
//
// Infinite loop kinda
int		loop_engine(t_win *w);
// Operation to choose the ball roll sprite
void	*get_ball_side(t_win *w);
// Makes the balls roll
void	ball_roll(t_win *w);
// Puts string on screen > Lacking support
void	string_on_screen(t_win *w);

/* <<< error.c >>>*/
//
// Prints error msg and exits
void	error_msg(char *str);

#endif