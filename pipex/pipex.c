/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:46 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/16 18:02:15 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
$> cmd1 << LIMITER | cmd2 >> file2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
*/

#include "pipex.h"

void initialization(t_pipex *pipex, char **argv, int argc, char **envp)
{
    if(ft_strncmp("here_doc", argv[1], 8) == 0)
    {
        pipex -> here_doc = 1;
        get_here_doc_input(pipex, argv);
    }
    else
        pipex -> here_doc = 0;
    /* 
    Command counter:
    //  ./pipex infile -command1 command2 command3- outfile                         argc - 3     for w/out here_doc: argc - 3

    //  ./pipex here_doc limiter -command1 command2 command3- outfile               argc - 4     for here_doc:       argc - 4
    */
    pipex -> command_counter = argc - 3 - (pipex -> here_doc);
    pipex -> pipe_nbr = 2 * ((pipex -> command_counter) - 1);
    pipex -> pipe_fd = (int *)malloc(sizeof(int) * (pipex -> pipe_nbr));
    if(!(pipex -> pipe_fd))
        msgError("main -> pipe_fd");
    pipex -> path_to_command = find_path(envp);
    if(!(pipex -> path_to_command))
        free_and_exit(pipex);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;

    if(check_input(argc, argv) == -1)
    {
        msgOnly("Wrong input. Invalid number of arguments.");
        exit(1);
    }
    initialization(&pipex, argv, argc, envp);
    open_files(&pipex, argv, argc);
    
    make_pipes(&pipex);
    pipex.child_num = -1;
    while(++(pipex.child_num) < pipex.command_counter)
        child_processes(pipex, argv, envp);

    close_pipes(&pipex);
    waitpid(-1, NULL, 0);
    free_all(&pipex);
    return (0);
}

int check_input(int argc, char **argv)
{
    if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6)
        return (-1);
    else if (argc < 5)
        return (-1);
    return (0);
}

char **find_path(char **envp)
{
    char **path;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
    envp[0] = envp[0] + 5;
	path = ft_split(*envp, ':');
    return (path);
}

int open_files(t_pipex *pipex, char **argv, int argc)
{
    if(pipex -> here_doc == 0)
    {
        pipex -> infile = open(argv[1], O_RDONLY);
        if(pipex -> infile == -1)
        {
            //testar se tudo funciona sem infile 
            msgError("open_files > OPEN INFILE");
        }
    }
    if (pipex -> here_doc == 1)
        pipex -> outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
    else if (pipex -> here_doc == 0)
        pipex -> outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
    if (pipex -> outfile < 0)
    {
        msgError("open_files > OPEN OUTFILE");
    }
    return (1);
}

void make_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < (pipex -> pipe_nbr) - 1)
    {
        if(pipe(pipex -> pipe_fd + 2 * i) < 0)
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
    while(i < (pipex -> pipe_nbr))
    {
        close(pipex -> pipe_fd[i]);
        i++;
    }
}
