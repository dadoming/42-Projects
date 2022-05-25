/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:37 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 17:33:15 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_only(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	msg_error(char *where)
{
	perror(where);
	exit(1);
}

void	msg_err_output(char *where, char *error)
{
	char	*str;

	str = "Error in function ";
	write(2, str, ft_strlen(str));
	write(2, where, ft_strlen(where));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

int	check_input(int argc, char **argv)
{
	if ((ft_strncmp(argv[1], "here_doc", 8) == 0) && argc < 6)
	{
		msg_only("\nInvalid number of arguments.\n");
		msg_only("Input:\n./pipex here_doc EOF \"cmd1\" \"cmd2\"");
		msg_only(" (...) \"cmdn\" outfile\n\n");
		return (-1);
	}
	else if (argc < 5)
	{
		msg_only("\nInvalid number of arguments.\n");
		msg_only("Input:\n./pipex infile \"cmd1\" \"cmd2\" (...) \"cmdn\" outfile\n\n");
		return (-1);
	}
	return (0);
}
