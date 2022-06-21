/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/21 04:20:07 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_win	w;

	if (argc != 2)
		error_msg("Wrong number of arguments");
	initialization(&w, argv[1]);
	w.mlx = mlx_init();
	if (!w.mlx)
		return (3);
	load_all_imgs1(&w);
	w.win = mlx_new_window(w.mlx, w.width * w.size_width,
			w.height * w.size_height, "so_long");
	if (!w.win)
		error_msg("Unable to create window");
	print_initial_map(&w, w.map);
	mlx_loop_hook(w.mlx, loop_engine, &w);
	mlx_hook(w.win, 2, 1L << 0, key_event, &w);
	mlx_hook(w.win, 17, 1L << 2, x_close_window, &w);
	mlx_loop(w.mlx);
	return (0);
}
