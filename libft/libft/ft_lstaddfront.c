/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:18 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:41:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstaddfront(t_list **lst, t_list *new)
{
    if(lst == NULL)
        return
    if(new == NULL)
    {
        *lst = new
        return
    }
    new -> next = *lst;
    *lst -> new;
}