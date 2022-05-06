/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:32 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/06 15:59:05 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_processes(t_pipex *pipex)
{
    pid_t pid;

    pid = fork();
    if(pid == 0)
    {
        // Change stdin to infile
        // Change stdout to pipe[stdout]
        // Unlink storer (?)
        if(pipex -> child_num == 0)
        {
            pipe_dupper(pipex -> infile, pipex -> pipe_fd[STDOUT_FILENO]);
            if(pipex -> here_doc == 1)
            {
                unlink("heredoc_storer");
            }
        }
        
        // Change stdin to pipe in parent process
        // Change stdout to outfile
        else if(pipex -> child_num == (pipex -> command_counter) - 1)
        {
            pipe_dupper(pipex -> pipe_fd[2 * pipex -> child_num - 2], pipex -> outfile);
        }
        
        // Change stdin to pipe inside parent
        // Change stdout to pipe inside child
        else
        {
            pipe_dupper(pipex -> pipe_fd[2 * pipex -> child_num - 2], pipex -> pipe_fd[2 * pipex -> child_num + 1]);
        }
        close_pipes(pipex);
        
        pipex -> command_arg = ft_split(pipex -> argv[2 + pipex -> here_doc + pipex -> child_num], ' ');
        if(get_command(pipex) == 0)
        {
            msgErrOutput("child_processes", "UNABLE TO GET COMMAND");
            free_child(pipex);
            exit(1);
        }
        execve(pipex -> command, pipex -> path_to_command, pipex -> envp);
        }
}

void pipe_dupper(int zero, int one)
{
    dup2(zero, 0);
    dup2(one, 1);
}

int get_command(t_pipex *pipex)
{
    char *tmp;
    char *cmd;
    int i;

    i = 0;
    while(pipex -> path_to_command[i])
    {
        tmp = pipex -> path_to_command[i];
        tmp = ft_strjoin(tmp, "/");
        cmd = ft_strjoin(tmp, pipex -> command_arg[0]);
        free(tmp);
        if(access(cmd, F_OK))
        {
            pipex -> command = cmd;
            return (1);
        }
        free(cmd);
        i++;
    }
    return(0);
}

