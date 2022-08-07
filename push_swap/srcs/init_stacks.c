#include "../push_swap.h"

t_list *init_stacks_string(char **splitted_argv)
{
    t_list *head;
    t_list *tmp;
    int i;
    
    i = 0;
    if(check_errors(splitted_argv) == -1)
        return(NULL);
    head = ft_lstnew(ft_atoi(splitted_argv[i++]));
    tmp = head;
    while (splitted_argv[i] != 0)
    {
        tmp -> next = ft_lstnew(ft_atoi(splitted_argv[i]));
        tmp = tmp -> next;
        i++;
    }
    tmp -> next = NULL;
    i = 0;
    while(splitted_argv[i])
    {
        free(splitted_argv[i]);
        i++;
    }
    free(splitted_argv[i]);
    return (head);
}

t_list *init_stacks(int argc, char **argv)
{
    t_list *head;
    t_list *tmp;
    int i;

    if(argc == 2)
        return (init_stacks_string(ft_split(argv[1], ' ')));
    i = 1;
    if(check_errors(argv) == -1)
        return NULL;
    head = ft_lstnew(ft_atoi(argv[i++]));
    tmp = head;
    while (i < argc)
    {
        tmp -> next = ft_lstnew(ft_atoi(argv[i]));
        tmp = tmp -> next;
        i++;
    }
    tmp -> next = NULL;
    return (head);
}
