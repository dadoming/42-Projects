/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:42 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/16 17:54:40 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_here_doc_input(t_pipex *pipex, char **argv)
{
    int file;
    char *buffer;

    // Creates a invisible file to store all input of here_doc
    file = open(".heredoc_storer", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
    if(file < 0)
    {
        msgError("get_here_doc_input -> OPEN FILE");
    }

    // Gets line from input and writes it to temporary file
    while(1)
    {
        write(STDOUT_FILENO, "pipe heredoc> ", 14);
        buffer = get_next_line(STDIN_FILENO);
        if(buffer[ft_strlen(argv[2])] == '\n' && ft_strncmp(argv[2], buffer, ft_strlen(argv[2])) == 0)
            break ;
        write(file, buffer, ft_strlen(buffer));
        write(file, "\n", 1);
        free(buffer);
    }
    free(buffer);
    close(file);
    
    pipex -> infile = open(".heredoc_storer", O_RDONLY);
    // If error in reading file then proceed to remove it
    if(pipex -> infile < 0)
    {
        unlink("heredoc_storer");
        msgError("get_here_doc_input -> OPEN STORER");
    }
}
