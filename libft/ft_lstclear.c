/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:06:13 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/04 17:26:10 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
    
    if(del == NULL)
        return;
    while (*lst != NULL)
    {
        temp = (*lst) -> next;
        del(*lst);
        free(*lst);
        *lst = temp;;
    }
    *lst = NULL;
}