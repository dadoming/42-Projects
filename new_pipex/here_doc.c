/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:42 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/06 15:30:46 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_here_doc_input(t_pipex *pipex)
{
    int file;
    int limiter_len;
    char *buffer;
    char *limiter;

    // Creates a invisible file to store all input of here_doc
    file = open("heredoc_storer", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
    if(file < 0)
    {
        msgError("get_here_doc_input -> OPEN FILE");
    }

    // Stores the limiter values
    limiter = pipex -> argv[2];
    limiter_len = ft_strlen(limiter);
    
    // Gets line from input and writes it to temporary file
    write(STDOUT_FILENO, "here_doc > ", 12);
    buffer = get_next_line(STDIN_FILENO);
    while(ft_strncmp(limiter, buffer, limiter_len) != 0)
    {
            write(file, buffer, ft_strlen(buffer));
            write(file, "\n", 1);
            write(STDOUT_FILENO, "here_doc > ", 12);
            free(buffer);
            buffer = get_next_line(STDIN_FILENO);
            if(buffer < 0)
            {
                exit(1);
            }
    }
    free(buffer);
    close(STDIN_FILENO);
    close(file);
    pipex -> infile = open("heredoc_storer", O_RDONLY);
    
    // If error in reading file then proceed to remove it
    if(pipex -> infile < 0)
    {
        unlink("heredoc_storer");
        msgError("get_here_doc_input -> OPEN STORER");
    }
}
