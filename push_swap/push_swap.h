/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:25:23 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 19:31:28 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node* next;
}   stack;

stack   *add_new_node(int data);
stack   *init_stacks_string(char **splitted_argv);
stack   *init_stacks(int argc, char **argv);

int main(int argc, char **argv);

int ft_atoi(const char *str);

char    *ft_substr(char const *s, unsigned int start, size_t len);

size_t  ft_amount_of_splits(char const *s, char c);
char    **ft_split(char const *s, char c);

#endif
