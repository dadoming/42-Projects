/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:42 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/23 18:58:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Creates a invisible file to store all input of here_doc

Gets line from input and writes it to temporary file

No need of \n cause get_next_line already sets new line in each enter-key click 

If error in reading file then proceed to remove it
*/

static int	to_stop(char *buffer, char *eof)
{
	if (buffer[ft_strlen(eof)] == '\n'
		&& ft_strncmp(eof, buffer, ft_strlen(eof)) == 0)
		return (0);
	else
		return (1);
}

void	get_here_doc_input(t_pipex *pipex, char **argv)
{
	int		file;
	char	*buffer;

	file = open(".heredoc_storer", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
	{
		msg_error("get_here_doc_input -> OPEN FILE");
	}
	while (1)
	{
		write(STDOUT_FILENO, "pipe heredoc> ", 14);
		buffer = get_next_line(STDIN_FILENO);
		if (to_stop(buffer, argv[2]) == 0)
			break ;
		write(file, buffer, ft_strlen(buffer));
		free(buffer);
	}
	free(buffer);
	close(file);
	pipex -> infile = open(".heredoc_storer", O_RDONLY);
	if (pipex -> infile < 0)
	{
		unlink("heredoc_storer");
		msg_error("get_here_doc_input -> OPEN STORER");
	}
}
