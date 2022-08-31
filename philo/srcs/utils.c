#include "../header/philo.h"

int	ft_atoi(const char *str)
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
			return (-2);
		if ((res * neg) > 2147483647)
			return (-1);
	}
	return ((int)res * neg);
}

// Checks input number 
int check_if_is_number(char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i])
    {
        if(!((str[i][j] == '+' ) || (str[i][j] >= '0' && str[i][j] <= '9')))
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

// Prints message to stderr
void err_msg(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}