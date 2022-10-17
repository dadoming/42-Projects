/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:24 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 18:47:39 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(int max_bits, int size)
{
	int	max_num;

	max_num = size - 1;
	while (max_num >> max_bits != 0)
		++max_bits;
	return (max_bits);
}

void	radix(t_list **a, t_list **b, int *radixs_array, int size)
{
	int	num;
	int	max_bits;
	int	j;
	int	i;

	max_bits = get_max_bits(0, size);
	i = -1;
	j = -1;
	while (++i < max_bits)
	{
		while (++j < size)
		{
			num = get_position((*a)->content, radixs_array);
			if (((num >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		j = -1;
		while (ft_lstsize(*b) > 0)
			pa(a, b);
	}
}

void	sort_big(t_list **a, t_list **b)
{
	int	*radixs_array;
	int	size;

	size = ft_lstsize(*a);
	radixs_array = malloc(size * sizeof(int));
	load_array(a, radixs_array, size);
	quicksort_array(radixs_array, size);
	radix(a, b, radixs_array, size);
	free(radixs_array);
}
