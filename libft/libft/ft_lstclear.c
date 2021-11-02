/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:06:13 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:41:34 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list temp;
    
    if(lst ==NULL)
        return;
    while (lst -> next != '\0')
    {
        temp = (*lst)->next; //pega no link do proximo endereco
        del(lst -> content); //faz delete do node atual
        free(lst);           //free do node atual
        *lst = temp;;        //atribui o proximo endereco ao pointer atual
    }
    lst = NULL;              //termina com pointer para null
}