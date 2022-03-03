#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include "libft.h" //colocar printf na libft
//procurar integrar o merge sort

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

/*
        THIS FUNCTION GIVES a_stack THE VALUES IT NEEDS TO START THE CALCULATIONS ACCORDING TO THE SUBJECT
        - alocates memory according to argc
        - gives a_stack the values of input in ./a.out
        - leaves b_stack initiated and empty
*/

void init_array(int *a, int *b, int argc, char **argv) 
{
   int i;
   
   a = (int *)malloc((argc - 1) * sizeof(int));
   b = (int *)malloc((argc - 1) * sizeof(int));
   i = 0;
   while (argv[i])
   {
       a[i] = ft_atoi(argv[i + 1]);
       b[i] = '\0';
       i++;
   }
}




int check_dup(int *n, int arg_num)
{
    int i;
    int aux;

    i = 1;
    aux = 0;
    while (n[i])
    {
        while (aux >= 0 && i < arg_num - 1)
        {
            if(n[i] == n[aux])
                return (1);
            aux--;
        }
        aux = i;
        i++;
    }
    return (0);
}


int check_input(char **input, int arg_num)
{
    int i;
    int j;

    i = 1;
    while(input[i])
    {
        if(!(ft_isdigit(input[i]) && input[i][1] == '\0')) // 1??   /// falta ainda para os casos negativos
            return (0);
        if (ft_atoi(input[i]) >= 2147483647 || ft_atoi(input[i]) <= -2147483648)
            return (0);
        if(check_dup(input, arg_num)) //mudar input, ta a receber um array de arrays na de dup
            return (0);
        else 
            i++;
    }
    return (1);
}

int main(int argc, char, **argv)
{
    int a_stack[]; 
    int b_stack[];

    /*
                # ERROS DE INPUT: (printar Error\n no stderr)
            
                #    - 0 one 2 3 
                #    - Não serem integers
                #    - Ser maior que integer (-2147483648 ate 2147483647)
                #    - Ter um duplicate

                # Em caso de nao haver input, o programa nao apresentará nada e voltará ao terminal Exit(0);
    */
   
    if (argc < 2 && check_input(argv, argc) == 0)
    {
        ft_printf ("Error! Check your input!\n");
        exit (0);
    }
    else
    {
        init_array(a_stack, b_stack, argc, argv);
    }
}
