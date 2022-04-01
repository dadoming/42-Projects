#include "push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *pop;
    int new_head_value;
    
    if(ft_lstsize(*stack_b) > 0)
    {
        pop = *stack_b;
        *stack_b = (*stack_b) -> next;
        new_head_value = pop -> content;
        //pop->next = *stack_a;
        ft_lstdelone(pop, NULL);
        ft_lstadd_front(stack_a, add_new_node(new_head_value));
        write(1, "pa\n", 3);
    }
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *pop;
    int new_head_value;
    
    if(ft_lstsize(*stack_a) > 0)
    {
        pop = *stack_a;
        *stack_a = (*stack_a) -> next;
        new_head_value = pop -> content;
        //pop->next = *stack_b;
        ft_lstdelone(pop, NULL);
        ft_lstadd_front(stack_b, add_new_node(new_head_value));
        write(1, "pb\n", 3);
    }
}




/*

void	push(t_list **s, t_list *new)
{
	if (s == NULL)
		return ;
	ft_lstadd_front(s, new);
}

int	*pop(t_list **s)
{
	int		*content;
	t_list	*poped;

	if (*s == NULL || s == NULL)
		return (NULL);
	poped = *s;
	*s = poped->next;
	content = poped->content;
	ft_lstdelone(poped, NULL);
    printf("test");
	return (content);
}


void	pa(t_list **a, t_list **b)
{
	if (ft_lstsize(*b) > 0)
	{
		push(a, ft_lstnew(pop(b)));
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 0)
	{
		push(b, ft_lstnew(pop(a)));
		write(1, "pb\n", 3);
	}
}
*/