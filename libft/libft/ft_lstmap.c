/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:28:26 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:41:47 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
    t_list *newlist;
    
    if(lst == NULL)
        return;
    while (lst -> next != '\0')
   {
        *newlist = malloc(sizeof(t_list));
        newlist -> content = f(lst -> next);
        free(*lst -> content);
        lst = lst -> next;
    }
    *newlist = malloc(sizeof(t_list));
    newlist -> next= '\0';
}