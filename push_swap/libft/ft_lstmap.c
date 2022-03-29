/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:28:26 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/29 18:01:34 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	temp = ft_lstnew(f(lst));
	if (!temp)
		return (0);
	new_list = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst));
		if (!temp->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	temp->next = NULL;
	return (new_list);
}
