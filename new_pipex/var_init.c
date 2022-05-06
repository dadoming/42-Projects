/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:07:06 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/06 14:40:34 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void initialize_vars(t_pipex *pipex, int argc, char **argv, char **envp)
{
    pipex -> argc = argc;
    pipex -> argv = argv;
    pipex -> envp = envp;

    pipex -> here_doc = 0;
    if(ft_strncmp("here_doc", argv[1], 9) == 0)
        pipex -> here_doc = 1;

    /* Command counter:
    //  ./pipex infile -command1 command2- outfile                                  argc => 5 - 3
    //  ./pipex infile -command1 command2 command3- outfile                         argc => 6 - 3     for w/out here_doc: argc - 3
    //  ./pipex infile -command1 command2 command3 command4- outfile                argc => 7 - 3 

    //  ./pipex here_doc limiter -command1 command2- outfile                        argc => 6 - 4
    //  ./pipex here_doc limiter -command1 command2 command3- outfile               argc => 7 - 4     for here_doc:       argc - 4
    //  ./pipex here_doc limiter -command1 command2 command3 command4- outfile      argc => 8 - 4
    */
    pipex -> child_num = 0;
    pipex -> command_counter = argc - 3 - pipex -> here_doc;
    pipex -> pipe_nbr = 2 * (pipex -> command_counter - 1);
    pipex -> pipe_fd = (int *)malloc(sizeof(int) * pipex -> pipe_nbr);

}