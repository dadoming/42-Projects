/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:38:06 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:57:36 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(int a_num, int *radixs_array)
{
	int	i;

	i = 0;
	while (a_num != radixs_array[i])
		i++;
	return (i);
}

void	load_array(t_list **a, int *radixs_array, int size)
{
	int		i;
	t_list	*temp;

	temp = *a;
	i = 0;
	while (i < size)
	{
		radixs_array[i] = temp -> content;
		temp = temp -> next;
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	quicksort_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] > array[i + 1])
		{
			ft_swap(&array[i], &array[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
