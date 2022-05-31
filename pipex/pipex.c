/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:46 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 17:38:37 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Command counter:

>>>>

http://www.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html

>>>>



./pipex infile -command1 command2 command3- outfile
-> for w/out here_doc: argc - 3

./pipex here_doc limiter -command1 command2 command3- outfile
-> for here_doc:       argc - 4
*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (check_input(argc, argv) == -1)
		exit(1);
	initialization(&pipex, argv, argc, envp);
	open_files(&pipex, argv, argc);
	make_pipes(&pipex);
	pipex.child_num = -1;
	while (++(pipex.child_num) < pipex.command_counter)
		child_processes(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	free_all(&pipex);
	return (0);
}

void	initialization(t_pipex *pipex, char **argv, int argc, char **envp)
{
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		pipex -> here_doc = 1;
		get_here_doc_input(pipex, argv);
	}
	else
		pipex -> here_doc = 0;
	pipex -> command_counter = argc - 3 - (pipex -> here_doc);
	pipex -> pipe_nbr = 2 * ((pipex -> command_counter) - 1);
	pipex -> pipe_fd = (int *)malloc(sizeof(int) * (pipex -> pipe_nbr));
	if (!(pipex -> pipe_fd))
		msg_error("main -> pipe_fd");
	pipex -> path_to_cmd = find_path(envp);
	if (!(pipex -> path_to_cmd))
		free_and_exit(pipex);
}

char	**find_path(char **envp)
{
	char	**path;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	envp[0] = envp[0] + 5;
	path = ft_split(*envp, ':');
	return (path);
}

int	open_files(t_pipex *pipex, char **argv, int argc)
{
	if (pipex -> here_doc == 0)
	{
		pipex -> infile = open(argv[1], O_RDONLY);
		if (pipex -> infile == -1)
			msg_error("open_files > OPEN INFILE");
	}
	if (pipex -> here_doc == 1)
		pipex -> outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else if (pipex -> here_doc == 0)
		pipex -> outfile = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (pipex -> outfile < 0)
		msg_error("open_files > OPEN OUTFILE");
	return (1);
}
