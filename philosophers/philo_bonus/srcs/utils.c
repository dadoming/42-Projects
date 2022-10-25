#include "../header/philo_bonus.h"

void print_status(t_philo *p, char *status, char *color)
{
    long long int current_time;

    current_time = get_delta_t(table()->time_start);
    sem_wait(table()->sem.print);
    printf("%s%lld", color, current_time);
    printf("  %d  %s%s\n", p->index, status, RESET);
    sem_post(table()->sem.print);
}

long	ft_atoi(const char *str)
{
	int			i;
	long 	neg;
	long	res;

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
		if (((res * neg) < INT_MIN) || ((res * neg) > INT_MAX))
			return (-1);
	}
	return ((int)res * neg);
}

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
