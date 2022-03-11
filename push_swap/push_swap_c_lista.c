/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c_lista.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:20:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 19:46:31 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_list *new_node

typedef t_list stack_l; //(t_list da libft)

void init_stack(argc, argv)
{
	int i;

	i = 0;
	while(argc < i)
	{
		if(check_errors(argv[i]))
		{
			return( )
		}
		a = malloc(sizeof(t_list));
		a.content = ft_atoi(argv[i]);
		a.next = head;
		a.prev = NULL;

		if (head != NULL)
			head.prev = a;
		
		i++;

		/*
		a.content = ft_lstnew(ft_atoi(argv[i]));
		a.next = head;
		*/

}


	}
}

int main(int argc, char **argv)
{
	stack_l *a;
	stack_l *b;

	if(argc > 1)
	{
		a = init_stack(argc, argv); //inicialização do stack a e a sua introdução de valores
	}
	

	->lstnew to create and alloc node
	->lstaddfront to add node to beggining of list
	
}
