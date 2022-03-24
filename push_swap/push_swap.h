/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:25:23 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/16 16:19:17 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
    int content;
    struct node* next;
}   stack;

int main(int argc, char **argv);

//PUSH_SWAP UTILS
stack   *add_new_node(int data);
stack   *init_stacks_string(char **splitted_argv);
stack   *init_stacks(int argc, char **argv);

//MOVES
void sa(stack **stack_a);
void sb(stack **stack_b);
void ss(stack **stack_a, stack **stack_b);

void ra(stack **stack_a);
void rb(stack **stack_a);
void rr(stack **stack_a, stack **stack_b);

void rra(stack **stack_a);
void rrb(stack **stack_b);
void rrr(stack **stack_a, stack **stack_b);

void pa(stack **stack_a, stack **stack_b);
void pb(stack **stack_a, stack **stack_b);

//ALGORITHM
stack *swap_three(stack *a);
stack *find_nodeth(stack *a, int nodeth);

//UTILS - LIBFT ----> COMPILAR COM LIBFT E COM OS NOMES DAS LISTAS CORRETOS APÓS TER
//                     ACABADO O PROJETO, DE MOMENTO ESTÁ ASSIM APENAS PARA O FAZER
int ft_atoi(const char *str);

char    *ft_substr(char const *s, unsigned int start, size_t len);

size_t  ft_amount_of_splits(char const *s, char c);
char    **ft_split(char const *s, char c);

int	ft_lstsize(stack *lst);
stack	*ft_lstlast(stack *lst);
void	ft_lstadd_front(stack **lst, stack *new);
void	ft_lstdelone(stack *lst, void (*del)(void *));


#endif
