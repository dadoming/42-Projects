/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:35:46 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/25 01:32:39 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

//PUSH_SWAP UTILS
t_list  *init_stacks_string(char **splitted_argv);
t_list  *init_stacks(int argc, char **argv);

//MOVES
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);

void    ra(t_list **stack_a);
void    rb(t_list **stack_a);
void    rr(t_list **stack_a, t_list **stack_b);

void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);

// ALGORITHM
int     lst_is_ordered(t_list *a);
int     get_position(int a_num, int *radixs_array);
int     get_smallest_elem(t_list **a, int size);
int     get_next_smallest_elem(int smallest, t_list **a);
void    get_radix_array(int *radixs_array, t_list **a);
void    sort_two(t_list **a);
void    sort_three(t_list **a);
void    sort_four(t_list **a, t_list **b);
void    sort_five(t_list **a, t_list **b);
void    sort_big(t_list **a, t_list **b);
void    radix(t_list **a, t_list **b);


// INPUT
int     check_input(char **argv, int argc);
int     check_input_string(char *arg);
int     check_errors(char **str);


#endif
