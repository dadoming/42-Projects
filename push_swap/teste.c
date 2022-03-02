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
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
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

int check_dup(int *n, int argc)
{
    int i;
    int pivot;

    i = 1;
    pivot = 0;
    while (n[i])
    {
        while (pivot >= 0 && i < argc - 1)
        {
            if(n[i] == n[pivot])
            {
                printf("%d | %d\n", n[i], n[pivot]);
                return (1);
            }
            pivot--;
        }
        pivot = i;
        i++;
    }
    return (0);
}


int main(int argc, char **argv)
{
    /*
    if (argc > 2)
    {
        printf("error\n");
        exit (0);
    } 
    */

    int i;
    int c[argc - 1];

    i = 1;
    while (argv[i])
    {
        c[i - 1] = ft_atoi(argv[i]);
        //printf("%d\n", c[i - 1]);
        i++;
    }
    if (check_dup(c, argc) == 1)
            printf("erro\n");
    return (0);
}