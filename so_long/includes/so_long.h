/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:19:41 by dadoming          #+#    #+#             */
/*   Updated: 2023/04/14 17:08:18 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_window{
	void	*mlx;
	void	*win;
	int		p_x;
	int		p_y;
	int		size_width;
	int		size_height;
	int		map_file;
	char	**map;
	int		width;
	int		height;
	int		floor_back;
	int		sprites_loaded;
	void	*wall_image1;
	void	*enemy_image;
	void	*floor_image;
	void	*coin_image;
	void	*coin_image2;
	void	*coin_image3;
	void	*exit_image;
	void	*exit_1;
	void	*exit_2;
	void	*exit_3;
	void	*p_img_up;
	void	*p_img_down;
	void	*p_img_left;
	void	*p_img_right;
	int		move_count;
	char	*m_count;
	int		not_over;
	int		winn;
	int		caught;
	int		c;
	int		p;
	int		e;
}	t_win;

/* <<< checker.c >>> */
//
// Checks map's input name
int		check_valid_map(const char *str);
// Check map variables
int		check_map_positions(char **map, t_win *w, int x, int y);
// Checks correct input of letters in map
int		check_variables(char c);

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
void	load_all_imgs1(t_win *w);
void	load_all_imgs2(t_win *w);
// Get the map in an array of strings ending in '\n'
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
// Prints string on game
void	print_string(t_win *w);

/* <<< move.c >>> */
//
// Selects the right action according to that key
int		key_event( int key, t_win *w);
// Changes value of p_x and p_y in accordance with key pressed
int		key_press(t_win *w, int key);
// Checks if key movement is valid
int		valid_key(int key, t_win *w);

/* <<< animations.c >>>*/
// Infinite loop
int		loop_engine(t_win *w);
// Operation to choose the ball roll sprite
void	*get_ball_side(t_win *w);
// Makes the balls roll
void	ball_roll(t_win *w);
// Checks size of move_string to print only the neccessary nbr of boxes
void	calculate_str_back(t_win *w);
// Makes Gengar spin when game is over as victory
void	victory(t_win *w);
// Makes player unable to move and enables spin win animation
void	exit_game_win(t_win *w);

/* <<< error.c >>>*/
//
// Prints error msg and exits
void	error_msg(char *str);
// Prints message on terminal
void	msg(char *str);

/* <<< close.c >>>*/
// Free everything and exit
void	ft_exit_game(t_win *w);
// Free map
void	free_map(t_win *w);
// Destroys sprites
void	free_sprites(t_win *w);

/* <<< img_control.c >>>*/
// Checks if the key can be accessed and clears player tile
void	put_back(t_win *w, int key, int x, int y);
// Sets floored tile to 0 and prints floor when ball caught
void	catch(t_win *w);
// Changes image to the player side
void	*which_side(t_win *w, int key);

#endif