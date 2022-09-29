/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:23:10 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:54:35 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	static t_list	*a;
	static t_list	*b;

	if (argc < 2)
	{
		print_msg("Wrong input.\nTry using: \
			./push_swap \"1 ... n\" or ./push_swap 1 ... n ", 1);
		return (1);
	}
	a = init_stacks(argc, argv);
	if (!a)
		return (2);
	if (!lst_is_ordered(a))
		sort(&a, &b);
	free_list(&a);
	return (0);
}
