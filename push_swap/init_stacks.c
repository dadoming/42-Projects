#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

stack	*add_new_node(int data)
{
	stack	*new_node;

	new_node = malloc(sizeof(stack));
	if (new_node == NULL)
		return (NULL);
    new_node -> content = data;
	new_node -> next = NULL;
    return (new_node);
}

stack *init_stacks_string(char **splitted_argv)
{
    stack *head_node;
    stack *tmp;
    int i;
    
    i = 0;
    head_node = NULL;
    while (splitted_argv[i])
    {
        //fazer a seguir  if(check_errors(argv[i]))
        //                  return NULL;
        if(i == 0)
        {
            head_node = add_new_node(ft_atoi(splitted_argv[i]));
            head_node -> next = tmp;
            tmp = head_node;
        }
        else
        {
            tmp -> next = add_new_node(ft_atoi(splitted_argv[i]));
            tmp = tmp -> next;
        }
        i++;
    }
    tmp -> next = NULL;
    return (head_node);
}

stack *init_stacks(int argc, char **argv)
{
    stack *head_node;
    stack *tmp;
    int i;

    if(argc == 2)
        return (init_stacks_string(ft_split(argv[1], ' ')));
    i = 1;
    head_node = NULL;
    while (i < argc)
    {
        //fazer a seguir  if(check_errors(argv[i]))
        //                  return NULL;
        if(i == 1)
        {
            head_node = add_new_node(ft_atoi(argv[i]));
            head_node -> next = tmp;
            tmp = head_node;
        }
        else
        {
            tmp -> next = add_new_node(ft_atoi(argv[i]));
            tmp = tmp -> next;
        }
        i++;
    }
    tmp -> next = NULL;
    return (head_node);
}
