/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:32 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/16 16:22:49 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_processes(t_pipex pipex, char **argv, char **envp)
{
    pipex.pid = fork();
    if(pipex.pid == 0)
    {
        // Change stdin to infile
        // Change stdout to pipe[stdout]
        // Unlink storer (?)
        if(pipex.child_num == 0)
        {
            pipe_dupper(pipex.infile, pipex.pipe_fd[STDOUT_FILENO]);
            if(pipex.here_doc == 1)
            {
                unlink(".heredoc_storer");
            }
        }
        
        // Change stdin to pipe in parent process
        // Change stdout to outfile
        else if(pipex.child_num == (pipex.command_counter) - 1)
        {
            pipe_dupper(pipex.pipe_fd[2 * pipex.child_num - 2], pipex.outfile);
        }
        
        // Change stdin to pipe inside parent
        // Change stdout to pipe inside child
        else
        {
            pipe_dupper(pipex.pipe_fd[2 * pipex.child_num - 2], pipex.pipe_fd[2 * pipex.child_num + 1]);
        }
        
        close_pipes(&pipex);
        pipex.command_arg = ft_split(argv[2 + pipex.here_doc + pipex.child_num], ' ');
        pipex.command = get_command(pipex.command_arg[0], pipex.path_to_command);
        if(!pipex.command)
        {
            msgErrOutput("child_processes", "UNABLE TO GET COMMAND");
            free_child(&pipex);
            exit(1);
        }
        execve(pipex.command, pipex.command_arg, envp);
    }
}

void pipe_dupper(int zero, int one)
{
    dup2(zero, 0);
    dup2(one, 1);
}


char *get_command(char *command, char **path_to_command)
{
    char *tmp;
    char *cmd;

    while(*path_to_command)
    {
        tmp = ft_strjoin(*path_to_command, "/");
        cmd = ft_strjoin(tmp, command);
        free(tmp);
        if(access(cmd, F_OK) == 0)
            return (cmd);
        free(cmd);
        path_to_command++;
    }
    return(NULL);
}
