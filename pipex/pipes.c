/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:34:33 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 17:35:02 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex -> pipe_nbr) - 1)
	{
		if (pipe(pipex -> pipe_fd + 2 * i) < 0)
		{
			free_all(pipex);
		}
		i++;
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex -> pipe_nbr))
	{
		close(pipex -> pipe_fd[i]);
		i++;
	}
}
