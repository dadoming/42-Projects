/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:25:23 by dadoming          #+#    #+#             */
/*   Updated: 2022/04/01 16:02:35 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

int main(int argc, char **argv);

//PUSH_SWAP UTILS
t_list   *add_new_node(int data);
t_list   *init_stacks_string(char **splitted_argv);
t_list   *init_stacks(int argc, char **argv);

//MOVES
void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);

void ra(t_list **stack_a);
void rb(t_list **stack_a);
void rr(t_list **stack_a, t_list **stack_b);

void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);

void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);

//ALGORITHM
t_list *sort_three(t_list **a);
/*
t_list *sort_f_f(t_list **a, t_list **b);
void sort_four(t_list **a, t_list **b);
void sort_five(t_list **a, t_list **b);
*/
t_list *sort_less_five(t_list **a, t_list **b);
void low_sorter(t_list **a, t_list **b);
void if_fits(t_list **a, t_list **b);
void put_on_top(t_list **a, t_list **b);
void put_one_more(t_list **a, t_list **b);
void last_biggest(t_list **a);


//UTILS
int ft_is_sorted(t_list **stack);

#endif
