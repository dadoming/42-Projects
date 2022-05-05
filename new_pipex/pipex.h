#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

// VARIABLES

typedef struct s_pipex{
    int argc;
    char **argv;
    char **envp;

    int infile;
    int outfile;

    int here_doc;
    
    int pipe_fd[2];

} t_pipex;

// PIPEX
void get_here_doc_input(t_pipex *pipex);
void initialize_vars(t_pipex *pipex, int argc, char **argv, char **envp);
int open_files(t_pipex *pipex);

// ERROR_HANDLING
void msgError(char *where);

// GET_NEXT_LINE

# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define BUFFER_SIZE 256

char	*read_file(int fd, char *text);
char	*get_line(char *text);
char	*extra_read(char *text);
char	*get_next_line(int fd);

#endif