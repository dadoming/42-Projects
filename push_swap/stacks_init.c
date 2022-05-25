/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:37:01 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 19:42:17 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *init_stacks_string(char **splitted_argv)
{
    t_list *head_node;
    t_list *tmp;
    int i;
    
    i = 0;
    head_node = NULL;
    while (splitted_argv[i])
    {
        //fazer a seguir  if(check_errors(argv[i]))
        //                  return NULL;
        if(i == 0)
        {
            head_node = ft_lstnew(ft_atoi(splitted_argv[i]));
            head_node -> next = tmp;
            tmp = head_node;
        }
        else
        {
            tmp -> next = ft_lstnew(ft_atoi(splitted_argv[i]));
            tmp = tmp -> next;
        }
        i++;
    }
    tmp -> next = NULL;
    return (head_node);
}

t_list *init_stacks(int argc, char **argv)
{
    t_list *head_node;
    t_list *tmp;
    int i;

    // For an input string
    if(argc == 2)
        return (init_stacks_string(ft_split(argv[1], ' ')));
    
    head_node = NULL;
    i = 1;
    while (i < argc)
    {
        //fazer a seguir  if(check_errors(argv[i]))
        //                  return NULL;
        if(i == 1)
        {
            head_node = ft_lstnew(ft_atoi(argv[i]));
            head_node -> next = tmp;
            tmp = head_node;
        }
        else
        {
            tmp -> next = ft_lstnew(ft_atoi(argv[i]));
            tmp = tmp -> next;
        }
        i++;
    }
    tmp -> next = NULL;
    return (head_node);
}
