/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:04:37 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/06 14:55:31 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void msgOnly(char *msg)
{
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 2);
}

void msgError(char *where)
{
    perror(where);
    exit(1);
}

void msgErrOutput(char *where, char *error)
{
    char *str;
    
    str = "Error in function ";
    write(2, str, ft_strlen(str));
    write(2, where, ft_strlen(where));
    write(2, ": ", 2);
    write(2, error, ft_strlen(error));
    write(2, "\n", 1);
}