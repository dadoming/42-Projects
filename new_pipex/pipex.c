/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:46 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/06 16:05:38 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;

    if(check_input(argc, argv) == -1)
    {
        msgOnly("Wrong input. Invalid number of arguments.");
    }
    initialize_vars(&pipex, argc, argv, envp);
    open_files(&pipex);
    if(pipex.here_doc == 1)
    {
        get_here_doc_input(&pipex);
    }
    find_path(&pipex, envp);
    if(!pipex.path_to_command)
    {
        free_and_exit(&pipex);
    }
    make_pipes(&pipex);
    if(!pipex.pipe_fd)
    {
        msgError("Main > Pipe");
    }
    while((pipex.child_num)++ < (pipex.command_counter) - 1)
    {
        child_processes(&pipex);
    }
    return (0);
}

int check_input(int argc, char **argv)
{
    if(argv[1] && ft_strncmp(argv[2], "here_doc",9) == 0)
    {
        if(argc < 6)
        {
            return (-1);
        }
    }
    else 
        if(argc < 5)
        {
            return (-1);
        }
    return (0);
}

void find_path(t_pipex *pipex, char **envp)
{
    char **path;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	path = ft_split(*envp, ':');
    path[0] = path[0] + 5;
    pipex -> path_to_command = path;
}

int open_files(t_pipex *pipex)
{
    if(pipex -> here_doc == 0)
    {
        pipex -> infile = open(pipex -> argv[1], O_RDONLY);
        if(pipex -> infile == -1)
        {
            //testar se tudo funciona sem infile 
            msgError("open_files > OPEN INFILE");
        }
    }
    if (pipex -> here_doc == 1)
	{
        pipex -> outfile = open(pipex -> argv[1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
    }
    else
    {
        pipex -> outfile = open(pipex -> argv[pipex -> argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
    }
    if(pipex -> outfile < 0)
    {
        msgError("open_files > OPEN OUTFILE");
    }
    return (1);
}

void make_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex -> pipe_nbr - 1)
    {
        if(pipe(&pipex -> pipe_fd[2 * i]) < 0)
        {
            free_all(pipex);
        }
        i++;
    }
}

void close_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while(i < pipex -> pipe_nbr)
    {
        close(pipex -> pipe_fd[i]);
        i++;
    }
}
