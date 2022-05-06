/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:52 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/06 15:39:39 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    
    int *pipe_fd;

    int child_num;
    int command_counter;
    int pipe_nbr;

    char **command_arg;
    char **path_to_command;
    char *command;

} t_pipex;

// PIPEX
void find_path(t_pipex *pipex, char **envp);
int open_files(t_pipex *pipex);
void make_pipes(t_pipex *pipex);
void close_pipes(t_pipex *pipex);
void free_and_exit(t_pipex *pipex);
void free_all(t_pipex *pipex);
int check_input(int argc, char **argv);

// CHILDS
void child_processes(t_pipex *pipex);
int get_command(t_pipex *pipex);
void pipe_dupper(int zero, int one);
void free_child(t_pipex *pipex);

// VAR_INIT
void initialize_vars(t_pipex *pipex, int argc, char **argv, char **envp);

// ERROR_HANDLING
void msgOnly(char *msg);
void msgError(char *where);
void msgErrOutput(char *where, char *error);

// HERE_DOC
void get_here_doc_input(t_pipex *pipex);

// GET_NEXT_LINE
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define BUFFER_SIZE 512

char	*read_file(int fd, char *text);
char	*get_line(char *text);
char	*extra_read(char *text);
char	*get_next_line(int fd);

#endif