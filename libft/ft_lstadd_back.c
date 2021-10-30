/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:20:57 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:41:22 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;
    
    if(*lst == NULL)
        return
    if(new == NULL)
    {
        *lst = new;
        return (lst)
    }
    
    temp = ft_lstlast(*lst);
    
    temp -> next = new; // o new e' o novo bloco de memoria a inserir 
}