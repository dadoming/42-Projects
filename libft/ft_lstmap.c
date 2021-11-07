/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:28:26 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/07 14:53:34 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
    t_list *newlist;
    t_list *temp;
    
    if (!lst || !del || !f)
        return(NULL);
    newlist = ft_lstnew(f(lst -> content));
    temp = newlist;
    while (lst -> next != NULL)
    {
        lst = lst -> next;
        temp -> next = ft_lstnew(f(lst -> content));
        temp = temp -> next;
        if (!temp)
        {
            ft_lstclear(&newlist, del);
            return (0);
        }
    }
    temp -> next = NULL;
    return (newlist);
}