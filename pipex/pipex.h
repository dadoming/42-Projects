/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:52 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/16 17:22:48 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"

// VARIABLES
typedef struct s_pipex{
    pid_t pid;
    
    int infile;
    int outfile;

    int here_doc;
    
    int *pipe_fd;

    int child_num;
    int command_counter;
    int pipe_nbr;

    char **path_to_command;
    char **command_arg;
    char *command;
} t_pipex;

// PIPEX
char **find_path(char **envp);
int open_files(t_pipex *pipex, char **argv, int argc);
void make_pipes(t_pipex *pipex);
void close_pipes(t_pipex *pipex);
int check_input(int argc, char **argv);
void initialization(t_pipex *pipex, char **argv, int argc, char **envp);

// CHILDS
void child_processes(t_pipex pipex, char **argv, char **envp);
char *get_command(char *command, char **path_to_command);
void pipe_dupper(int zero, int one);

// ERROR_HANDLING
void msgOnly(char *msg);
void msgError(char *where);
void msgErrOutput(char *where, char *error);

// HERE_DOC
void get_here_doc_input(t_pipex *pipex, char **argv);

//FREE
void free_child(t_pipex *pipex);
void free_and_exit(t_pipex *pipex);
void free_all(t_pipex *pipex);

#endif
