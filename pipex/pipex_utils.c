#include "pipex.h"

void msg_werror(char *error_message)
{
    perror(error_message);
    exit(EXIT_FAILURE);
}

int check_number_args(int argc)
{
    if(argc != 5)
    {
        write(1, ">> Input is wrong, try: infile \"command1\" \"command2\" outfile\n", 62);
        return(-1);
    }
    return(1);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void free_parent(t_pipex *pipex)
{
    int i;

    close(pipex -> infile);
    close(pipex -> outfile);
    i = 0;
    while(pipex -> command_path[i])
    {
        free(pipex -> command_path[i]);
        i++;
    }
    free(pipex -> command_path);
}

void free_child(t_pipex *pipex)
{
    int i;

    i = 0;
    while(pipex -> cmd_arg[i])
    {
        free(pipex -> cmd_arg[i]);
        i++;
    }
    free(pipex -> cmd_arg);
    free(pipex -> cmd);
}
