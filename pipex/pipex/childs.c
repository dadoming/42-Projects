/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:32 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 17:51:15 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

	// child_num = 0
		// Change stdin to infile
		// Change stdout to pipe[stdout]
		// Unlink storer (?)

	// child_num = last
		// Change stdin to pipe in parent process
		// Change stdout to outfile

	// child_num in between
		// Change stdin to pipe inside parent
		// Change stdout to pipe inside child

static void	pipes_dup(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

void	child_processes(t_pipex p, char **argv, char **envp)
{
	p.pid = fork();
	if (p.pid == 0)
	{
		if (p.child_num == 0)
		{
			pipes_dup(p.infile, p.pipe_fd[STDOUT_FILENO]);
			if (p.here_doc == 1)
				unlink(".heredoc_storer");
		}
		else if (p.child_num == (p.command_counter) - 1)
			pipes_dup(p.pipe_fd[2 * p.child_num - 2], p.outfile);
		else
			pipes_dup(p.pipe_fd[2 * p.child_num - 2],
				p.pipe_fd[2 * p.child_num + 1]);
		close_pipes(&p);
		p.command_arg = ft_split(argv[2 + p.here_doc + p.child_num], ' ');
		p.command = get_command(p.command_arg[0], p.path_to_cmd);
		if (!p.command)
		{
			msg_err_output("child_processes", "UNABLE TO GET COMMAND");
			free_child(&p);
			exit(1);
		}
		execve(p.command, p.command_arg, envp);
	}
}

char	*get_command(char *command, char **path_to_cmd)
{
	char	*tmp;
	char	*cmd;

	while (*path_to_cmd)
	{
		tmp = ft_strjoin(*path_to_cmd, "/");
		cmd = ft_strjoin(tmp, command);
		free(tmp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		path_to_cmd++;
	}
	return (NULL);
}
