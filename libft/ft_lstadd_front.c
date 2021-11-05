/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:19:20 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/04 18:19:21 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstaddfront(t_list **lst, t_list *new)
{
    t_list *temp;
    
    if(lst == NULL)
        return;
    if(new == NULL)
    {
        *lst = new;
        return;
    }
    temp = *lst;
    *lst = new;
    new -> next = temp;
}