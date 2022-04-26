#include "pipex.h"
#include <stdio.h> //trocar pelo ft_printf
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
Shell command:
     
     < file1 cmd1 | cmd2 > file2

Execution:

    ./pipex infile "ls -l" "wc -l" outfile
        
        em shell será: 
                < infile ls -l | wc -l > outfile

    ./pipex infile "grep a1" "wc -w" outfile
        
        em shell será: 
                < infile grep a1 | wc -w > outfile
*/


void first_child(t_pipex pipex, char **argv, char **envp)
{
    dup2(pipex.fd[STDOUT_FILENO], STDOUT_FILENO);
    close(pipex.fd[STDIN_FILENO]);
    dup2(pipex.infile, STDIN_FILENO);
    pipex.cmd_arg = ft_split(argv[2], ' ');
    pipex.cmd = analyze_command(pipex.command_path, pipex.cmd_arg[0]);
    if(!pipex.cmd)
    {
        free_child(&pipex);
        ft_putstr_fd(COMMAND_NOT_FOUND, 2);
        exit(EXIT_FAILURE);
    }
    execve(pipex.cmd, pipex.cmd_arg, envp);
}

void second_child(t_pipex pipex, char **argv, char **envp)
{
    dup2(pipex.fd[STDIN_FILENO], STDIN_FILENO);
    close(pipex.fd[STDOUT_FILENO]);
    dup2(pipex.outfile, STDOUT_FILENO);
    pipex.cmd_arg = ft_split(argv[3], ' ');
    pipex.cmd = analyze_command(pipex.command_path, pipex.cmd_arg[0]);
    if(!pipex.cmd)
    {
        free_child(&pipex);
        ft_putstr_fd(COMMAND_NOT_FOUND, 2);
        exit(EXIT_FAILURE);
    }
    execve(pipex.cmd, pipex.cmd_arg, envp);
}

int *open_files(t_pipex *pipex, char **argv, int argc)
{
    pipex -> infile = open(argv[1], O_RDONLY);
    if(pipex -> infile < 0) 
        perror("Infile");
    pipex -> outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
    if(pipex -> outfile < 0)
    {
        msg_werror("Outfile");        
        exit (EXIT_FAILURE);
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
    
    if (check_number_args(argc) == -1)
        return(-1);
    open_files(&pipex, argv, argc);
    if(pipe(pipex.fd) < 0)
        perror("Pipe");
    pipex.path = find_path(envp);
    pipex.command_path = ft_split(pipex.path, ':');
    pipex.pid1 = fork();
    if(pipex.pid1 == 0)
        first_child(pipex, argv, envp);
    pipex.pid2 = fork();
    if(pipex.pid2 == 0)
        second_child(pipex, argv, envp);
    close_pipes(&pipex);
    waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
    free_parent(&pipex);
    return(0);   
}


