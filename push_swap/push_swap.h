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

# define FIRST  (*a)-> content
# define SECOND (*a)-> next -> content
# define THIRD  (*a)-> next -> next -> content
# define FORTH  (*a)-> next -> next -> next -> content
# define FIFTH  (*a)-> next -> next -> next -> next -> content

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"

//PUSH_SWAP UTILS
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

// ALGORITHM
int lst_is_ordered(t_list *a);
t_list *sort_two(t_list **a);
t_list *sort_three(t_list **a);
t_list *sort_four(t_list **a, t_list **b);
t_list *sort_five(t_list **a, t_list **b);

// INPUT
int check_input(char **argv, int argc);
int check_input_string(char **arg);

#endif
