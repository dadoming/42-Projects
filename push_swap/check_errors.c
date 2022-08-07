#include "push_swap.h"

static int check_repeat(char **str);
static int check_if_is_number(char **str);
static int check_size_of(char **str);

int check_errors(char **str)
{
    if(check_repeat(str) == -1)
    {
        printf("Repeat checker\n");
        return (-1);
    }
    if(check_if_is_number(str) == -1)
    {
        printf("Checker if is only number checker\n");
        return (-1);
    }
    if(check_size_of(str) == -1)
    {
        printf("Size of checker\n");
        return (-1);
    }
    return (0);
}

static int check_size_of(char **str)
{
    int i;
    int checker;
    char *check_str;

    i = 1;
	while (str[i])
	{
		checker = ft_atoi(str[i]);
		check_str = ft_itoa(checker);
		if (ft_strncmp(str[i], check_str, ft_strlen(str[i])) != 0)
		{
			free(check_str);
			return (-1);
		}
		free(check_str);
        i++;
    }
	return (0);
}

static int check_if_is_number(char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i])
    {
        if(!((str[i][j] == '+' || str[i][j] == '-')
            || (str[i][j] >= '0' && str[i][j] <= '9')))
            return (-1);
        j++;
        while (str[i][j] != '\0')
        {
            if (!(str[i][j] >= '0' && str[i][j] <= '9'))
                return (-1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

static int check_repeat(char **str)
{
    int i;
    int j;

    i = 1;
    while (str[i] != 0)
    {
        j = i + 1;
        while (str[j] != 0)
        {
            if(ft_strncmp(str[i], str[j], ft_strlen(str[j]) + ft_strlen(str[j])) == 0)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}