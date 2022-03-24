#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str) //ta no libft
{
	int			i;
	int			neg;
	long int	res;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if ((res * neg) < -2147483648)
			return (0);
		if ((res * neg) > 2147483647)
			return (-1);
	}
	return ((int)res * neg);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_amount_of_splits(char const *s, char c)
{
	size_t	split_amount;
	size_t	i;

	split_amount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			split_amount++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (split_amount);
}

char	**ft_split(char const *s, char c)
{
	size_t			end;
	size_t			i;
	char			**split;
	const char		*start;

	i = 0;
	split = malloc((ft_amount_of_splits(s, c) + 1) * sizeof(*split));
	if (!split)
		return (0);
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		end = 0;
		while (*s && *s != c)
		{
			end++;
			s++;
		}
		if (*(s - 1) != c)
			split[i++] = ft_substr(start, 0, end);
	}
	return (split);
}

int	ft_lstsize(stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

void	ft_lstadd_front(stack **lst, stack *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

stack	*ft_lstlast(stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstdelone(stack *lst, void (*del)(void *))
{
	if (del == NULL)
		return ;
	if (lst != NULL)
	{
		(*del)(lst -> content);
		free(lst);
	}
}
