#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;

    // Initialize all struct variables
    initialize_vars(&pipex, argc, argv, envp);
    
    //open_files(&pipex);
    if(pipex.here_doc == 1)
    {
        get_here_doc_input(&pipex);
    }
    return (0);
}

int open_files(t_pipex *pipex)
{
    if(pipex -> here_doc == 0)
    {
        pipex -> infile = open(pipex -> argv[1], O_RDONLY);
    }
    if(pipex -> infile == -1)
    {
        return(-1);
    }
    pipex -> outfile = open(pipex -> argv[pipex -> argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
    return (1);
}

void initialize_vars(t_pipex *pipex, int argc, char **argv, char **envp)
{
    pipex -> argc = argc;
    pipex -> argv = argv;
    pipex -> envp = envp;

    pipex -> here_doc = 0;
    if(ft_strncmp("here_doc", argv[1], 9) == 0)
        pipex -> here_doc = 1;

}


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
