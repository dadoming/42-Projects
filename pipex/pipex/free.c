/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:03 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 17:30:05 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex -> command_arg[i])
	{
		free(pipex -> command_arg[i]);
		i++;
	}
	free(pipex -> command_arg);
	free(pipex -> command);
}

void	free_and_exit(t_pipex *pipex)
{
	if (pipex -> here_doc == 1)
		unlink(".heredoc_storer");
	free(pipex -> pipe_fd);
	close(pipex -> infile);
	close(pipex -> outfile);
	msg_only("No path found in ENVP\n");
	exit(1);
}

void	free_all(t_pipex *pipex)
{
	int	i;

	close(pipex -> infile);
	close(pipex -> outfile);
	i = 0;
	while (pipex -> path_to_cmd[i])
	{
		free(pipex -> path_to_cmd[i]);
		i++;
	}
	free(pipex -> path_to_cmd);
	free(pipex -> pipe_fd);
}
