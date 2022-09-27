#include "../push_swap.h"

int lst_is_ordered(t_list *a)
{
    while(1)
    {
        if(a -> next == NULL)
        {
            return (0);
        }
        if(a -> content < a -> next -> content)
            a = a -> next;
        else
            break;
    }
    return(1);
}

void free_list(t_list **a)
{
    t_list	*temp;

	if (!a)
		return ;
	while (*a != NULL)
	{
		temp = (*a)-> next;
		free(*a);
		*a = temp;
	}
	a = NULL;
}

void print(t_list *a, t_list *b)
{
    printf("Stack a: ");
    while (a -> next)
    {
        printf("%d ", a->content);
        a = a -> next;
    }
    printf("%d\n", a -> content);
    if(b != NULL)
    {
        printf("Stack b: ");
        while (b -> next)
        {
            printf("%d ", b -> content);
            b = b -> next;
        }
        printf("%d\n", b -> content);
    }
}

// status = 1 for error / = 0 for just plain output
void print_msg(char *str, int status)
{
    if (status == 0)
    {
        write(STDOUT_FILENO, str, ft_strlen(str));
        write(STDOUT_FILENO, "\n", 2);
    }
    if (status == 1)
    {
        write(STDOUT_FILENO, "\e[1;31m", 7);
        write(STDOUT_FILENO, str, ft_strlen(str));
        write(STDOUT_FILENO, "\e[0m\n", 6);
    }
}