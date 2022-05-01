#ifndef PIPEX_H
# define PIPEX_H

//ERROR HANDLING
# define COMMAND_NOT_FOUND "Command not found"

//INCLUDES
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

//INFO_VAR
typedef char* string;
typedef char** ;//comecar a usar isto para sintaxe mais bonita 

typedef struct s_pipex{
    
    pid_t pid1;
    pid_t pid2;
    int infile;
    int outfile;
    int fd[2];
    char *path;
    char **command_path;
    char *cmd;
    char **cmd_arg;

}   t_pipex ;


//PIPEX
int main(int argc, char **argv, char **envp);
int *open_files(t_pipex *pipex, char **argv, int argc);
void first_child(t_pipex pipex, char **argv, char **envp);
void second_child(t_pipex pipex, char **argv, char **envp);

//VAR_MANAGE
char *find_path(char **envp);
char *analyze_command(char **paths, char *command);

//PIPEX_UTILS
int check_number_args(int argc);
void msg_werror(char *error_message);
void free_child(t_pipex *pipex);
void free_parent(t_pipex *pipex);
void close_pipes(t_pipex *pipex);

#endif
